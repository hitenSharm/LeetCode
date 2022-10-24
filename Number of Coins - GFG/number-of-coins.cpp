//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	vector<vector<int>>dp;
	
	int recu(int coins[],int n,int t,int idx)
	{
	    if(t==0)return 0;
	    if(idx>=n || coins[idx]>t || t<0)return -1;
	    if(dp[t][idx]!=-2)return dp[t][idx];
	    
	    int take=recu(coins,n,t-coins[idx],idx);//case of 5,1 and need 16
	    int noTake=recu(coins,n,t,idx+1);
	    if(take!=-1 and noTake!=-1){
	        return dp[t][idx]=min(1+take,noTake);
	    }
	    else if(take!=-1){
	        return dp[t][idx]=1+take;
	    }
	    return dp[t][idx]=noTake;
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins,coins+M);
	    dp.resize(V+1,vector<int>(M,-2));
	    return recu(coins,M,V,0);
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