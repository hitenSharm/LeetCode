// https://leetcode.com/problems/perfect-squares

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+2,INT_MAX);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        if(n<=3)return dp[n];
        for(int i=4;i<=n;i++)
        {
            int t=sqrt(i);
            if(t*t==i)
            {
                dp[i]=1;
                continue;
            }
            for(int j=i-1;j>=t;j--)
            {
              dp[i]=min(dp[i],(dp[j]+dp[i-j]));
            }
        }
        return dp[n];
    }
};