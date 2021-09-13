// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        if(nums.size()==1)
            return nums[0];
        int r=nums.size()-1;
        int pivot;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums[m]>nums[m-1]&&nums[m]>nums[m+1])
            { 
                pivot=m+1;
                break;
            }
            if(nums[m]>nums[l]&&nums[m]<nums[m+1])
            {
                r=m-1;
            }
            if(nums[m]<nums[l]&&nums[m]<nums[m+1])
            { 
                l=m+1;
            }
        }
        return nums[pivot];
    }
};