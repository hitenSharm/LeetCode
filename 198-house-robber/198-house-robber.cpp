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

    // int recu(int i,vector<int>& nums,vector<int>& dp)
    // {
    //     if(i<0)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     int robbed=nums[i]+recu(i-2,nums,dp);
    //     int notrobbed=recu(i-1,nums,dp);
    //     return max(robbed,notrobbed);
    // }

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int>dp(nums.size(),0);
        dp[0]=nums[0];
        dp[1]=max(nums[1],dp[0]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};