// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return min(nums[0],nums[1]);
        if(nums[nums.size()-1]>nums[0])
            return nums[0];
        int r=nums.size()-1;
        int pivot=0;
        while(l<=r)
        {
            int m=(l+r)/2;
            
            if(nums[m]>nums[m+1]&&m<nums.size()-1)
            { 
                pivot=m+1;
                return nums[pivot];
               // break;
            }        
            if(nums[m]>=nums[l])
            { 
                l=m+1;
            }
            else
                r=m-1;
        }
        return nums[0];
    }
};