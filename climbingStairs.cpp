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

    int dp[1001];

    int recu(vector<int>& cost,int index)
    {
      if(index>=cost.size())
        return 0;
      
      if(dp[index]!=-1)
        return dp[index];

      return dp[index]=min(cost[index]+recu(cost,index+1),cost[index]+recu(cost,index+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        int ans=min(recu(cost,0),recu(cost,1));
        return ans;
    }
};