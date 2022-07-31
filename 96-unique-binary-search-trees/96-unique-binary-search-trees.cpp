class Solution {
public:
    
    int recu(int n,vector<int>& dp)
    {
        if(n<=0)return 1;
        if(n==1 || n==2)return n;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=recu(i-1,dp)*recu(n-i,dp);
        return dp[n]=ans;
    }
    
    
    int numTrees(int n) {
      //partition dp  
        vector<int>dp(n+1,-1);
        return recu(n,dp);
    }
};