class Solution {
public:
    int dp[20];
    int recu(int n)
    {
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int j=0;j<n;j++)
        {
            ans+=recu(j) * recu(n-j-1);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return recu(n);
    }
};