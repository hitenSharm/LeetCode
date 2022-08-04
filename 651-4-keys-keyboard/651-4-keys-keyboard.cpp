class Solution {
public:  
    int maxA(int n) {        
        int dp[51]={0};
        for(int i=1;i<=n;i++)
        {
            if(i<=6)dp[i]=i;
            else
            {
                for(int j=i-3;j>=1;j--)
                {
                    dp[i]=max(dp[i],dp[j]*(i-j-1));
                }
            }
        }
        return dp[n];
    }
};