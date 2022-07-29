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
    int findMin(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(m+1<nums.size() and nums[m]>nums[m+1])return nums[m+1];
            if(m-1>=0 and nums[m]<nums[m-1])return nums[m];
            if(nums[m]>nums[0])
            {
                l=m+1;
            }
            else
                r=m-1;
        }
        return nums[0];
    }
};