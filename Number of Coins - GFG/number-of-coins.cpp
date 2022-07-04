// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
    vector<vector<int>>dp;

	int recu(int coins[], int M, int V,int index)
	{
		if(V==0)return 0;
		if(V<0 || index>=M)return 100001;

		if(dp[index][V]!=-1)return dp[index][V];

		return dp[index][V]=min(1+recu(coins,M,V-coins[index],index+1),min(recu(coins,M,V,index+1),1+recu(coins,M,V-coins[index],index)));
	}

	int minCoins(int coins[], int M, int V) 
	{ 
		dp.resize(M,vector<int>(V+1,-1));
	    sort(coins,coins+M,greater<int>());
	    int ans=recu(coins,M,V,0);
	    if(ans>=100001)ans=-1;
	    return ans;
	} 
	  
};

// { Driver Code Starts.
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