// https://leetcode.com/problems/find-peak-element

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
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)return 0;
        
        if(nums.size()>1)
        {
            if(nums[0]>nums[1])
            return 0;
            
            if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        }
        
        int l=0,r=nums.size()-1;
        int peak;
        while(l<=r)
        {
            int m=l + (r-l)/2;
            if(m+1>nums.size() || m-1<0)break;
            
            if(nums[m]>nums[m+1] and nums[m]>nums[m-1])
            {
                peak=m;
                break;
            }
            
            if(nums[m-1]<=nums[m] and nums[m]<=nums[m+1])
            {
                l=m;
                continue;
            }
            else
            r=m;
        }
        return peak;
    }
};