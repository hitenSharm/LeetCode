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

    // vector<int>dp;

    // int recu(vector<int>& nums,int& k,int index)
    // {
    //   if(index>=nums.size())
    //     return 0;
    //   if(index==nums.size()-1)
    //       return nums[index];
      
    //   if(dp[index]!=INT_MIN)
    //     return dp[index];

    //   int cost=nums[index];              
    //   int rIndex=index+k;
    //   if(rIndex>nums.size()-1)
    //       rIndex=nums.size()-1;
    //   for(int i=index+1;i<=rIndex;i++)
    //   {
    //     dp[index]=max(dp[index],cost+recu(nums,k,i));
    //     if(nums[i]>=0)
    //         break;
    //   }
    //   return dp[index];
    // }
    //DP approach
    int maxResult(vector<int>& nums, int k) {
      deque<int>dq;
      int n=nums.size();
      dq.push_back(n-1);
      for(int i=n-2;i>=0;i--)
      {
        if(dq.front()-i>k)dq.pop_front();
        nums[i]=nums[dq.front()]+nums[i];
        while(dq.size() and nums[dq.back()] < nums[i])
          dq.pop_back();
        dq.push_back(i);
      }
      return nums[0];
    }
};