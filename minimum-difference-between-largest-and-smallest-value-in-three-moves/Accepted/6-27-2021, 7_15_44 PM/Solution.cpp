// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves

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
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        if(nums.size()<=3)
        return 0;
        ans=min(ans,nums[nums.size()-4]-nums[0]);
        ans=min(ans,nums[nums.size()-1]-nums[3]);
        ans=min(ans,nums[nums.size()-3]-nums[1]);
        ans=min(ans,nums[nums.size()-2]-nums[2]);
        
        return ans;
        
    }
};