// https://leetcode.com/problems/stone-game-vii

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

    int dp[1001][1001];

    int recu(vector<int>& stones,int i,int j,int sumArr)
    {
      if(sumArr<=0 || i>=stones.size() || j<0 || i==j)
      return 0;

      if(dp[i][j]!=-1)
        return dp[i][j];

      return dp[i][j]=max(sumArr-stones[i]-recu(stones,i+1,j,sumArr-stones[i]),sumArr-stones[j]-recu(stones,i,j-1,sumArr-stones[j]));      
    }

    int stoneGameVII(vector<int>& stones) {
      memset(dp,-1,sizeof(dp));
      int sumArr=accumulate(stones.begin(),stones.end(),0);
      int i=0;int j=stones.size()-1;
      int ans=recu(stones,i,j,sumArr);
      return ans;
    }
};