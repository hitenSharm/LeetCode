// https://leetcode.com/problems/jump-game-vi

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

    vector<int>dp;

    int recu(vector<int>& nums,int& k,int index)
    {
      if(index>=nums.size())
        return 0;
      if(index==nums.size()-1)
          return nums[index];
      
      if(dp[index]!=INT_MIN)
        return dp[index];

      int cost=nums[index];              
      int rIndex=index+k;
      if(rIndex>nums.size()-1)
          rIndex=nums.size()-1;
      for(int i=index+1;i<=rIndex;i++)
      {
        dp[index]=max(dp[index],cost+recu(nums,k,i));
        if(nums[i]>=0)
            break;
      }
      return dp[index];
    }

    int maxResult(vector<int>& nums, int k) {
      dp.resize(nums.size(),INT_MIN);
        int ans=recu(nums,k,0);
        return ans;
    }
};