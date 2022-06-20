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
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int ans;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]==target)return m;
            if(nums[m]>target)
            {
                ans=m;
                r=m-1;
            }
            else
            {
                ans=m+1;
                l=m+1;
            }
        }
        if(ans==-1)ans=0;
        return ans;
    }
};