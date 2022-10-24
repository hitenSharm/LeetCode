//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<int>dp;
	//v*m memoise method -> v*m and v memoise also possible
	
// 	int recu(int coins[],int n,int t)
// 	{
// 	    if(t==0)return 0;
// 	    if(t<0)return -1;
// 	    if(dp[t]!=-2)return dp[t];
// 	    int ans=INT_MAX;
// 	    for(int i=0;i<n;i++)
// 	    {
// 	        int temp=recu(coins,n,t-coins[i]);
// 	        if(temp!=-1)ans=min(ans,1+temp);
// 	    }
// 	    if(ans==INT_MAX)ans=-1;
// 	    return dp[t]=ans;
// 	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins,coins+M);
	    dp.resize(V+1,-2);
	    dp[0]=0;
	    for(int t=1;t<=V;t++)
	    {
	        int ans=INT_MAX;
	        for(int i=0;i<M;i++)
	        {
	            if(t-coins[i]>=0 and dp[t-coins[i]]!=-1)
	            {
	                ans=min(ans,1+dp[t-coins[i]]);
	            }
	        }
	        if(ans==INT_MAX)ans=-1;
	        dp[t]=ans;
	    }
	    return dp[V];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends