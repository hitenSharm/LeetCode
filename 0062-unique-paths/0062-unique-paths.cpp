class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long>>dp(m+1,vector<long>(n+1,0));
        for(int i=m;i>=0;i--)
        {
            dp[i][n]=1;
        }
        for(int j=n;j>=0;j--)
        {
            dp[m][j]=1;
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        return dp[1][1];
    }
};