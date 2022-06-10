
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
        if(n==1 || n==2)return n;
        vector<int>dp(n+1,INT_MAX);
        dp[1]=1;
        dp[2]=2;        
        for(int i=3;i<=n;++i)
        {
            int tmp=sqrt(i);
            if(tmp*tmp==i)
            dp[i]=1;
            else
            {
                int mini=INT_MAX;
                for(int j=1;j*j<=i;++j)
                {
                    mini=min(mini,1+dp[i-j*j]);
                    if(mini==2)break;
                }
                dp[i]=mini;
                //as at each minimum can be a square(1 operation) + i-square
            }
        }        
        return dp[n];
    }
};