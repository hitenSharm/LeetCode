// https://leetcode.com/problems/unique-binary-search-trees

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

    int dp[20];

    int recu(int n)
    {
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=recu(i)*recu(n-i-1);
        }
        return dp[n]=ans;
    }

    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return recu(n);
    }
};