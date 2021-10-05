class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[nums.size()-1]>nums[nums.size()-2])return nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(m-1>=0 and m+1<nums.size() and nums[m]>nums[m-1] and nums[m]>nums[m+1])return m;
            else if(m+1<nums.size() and nums[m]<nums[m+1])l=m+1;
            else if(m-1>=0 and nums[m]<nums[m-1])r=m-1;
            else
                break;
        }
        return nums.size()-1;
    }
};