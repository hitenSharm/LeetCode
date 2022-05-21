class Solution {
public:
	long long dp[10001];
	long long recu(long long amt,vector<int>& coins, int& amount)
	{
		if(amt>amount)return 100000;
		if(amt==amount)return 0;	
		if(dp[amt]!=-1)return dp[amt];	
		long long ans=INT_MAX;
		for(int i=0;i<coins.size();i++)
		{
			ans=min(ans,1+recu(amt+coins[i],coins,amount));
		}
		return dp[amt]=ans;
	}

    int coinChange(vector<int>& coins, int amount) {
		memset(dp,-1,sizeof(dp));
        long long ans=recu(0,coins,amount);
        if(ans>=100000)
            ans=-1;
        return ans;
    }
};