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
        if(n==1)return 1;
        vector<int>dp(n+2,INT_MAX);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;        
        for(int i=4;i<=n;i++)
        {
            int t=sqrt(i);
            if(t*t==i)
            {
                dp[i]=1;
                continue;
            }
            for(int j=1;j*j<=i;j++)
            {
              dp[i]=min(dp[i],(dp[i-j*j]+1));
              if(dp[i]==2)break;
            }
        }
        return dp[n];
    }
};