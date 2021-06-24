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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int st=-1,en=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<left)
            {
                ans=ans+en-st;
                continue;
            }
            if(nums[i]>=left and nums[i]<=right)
            {
                en=i;
                ans=ans+en-st;
                continue;
            }
            else
            {
                st=i;
                en=i;
            }
        }
        return ans;
    }
};