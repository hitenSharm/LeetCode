// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<nums.size() - 1 && nums[left+1]>=nums[left])
        {
            left++;
        }
        while(right>0 && nums[right-1]<=nums[right])
        {
            right--;
        }
        if(right>left)
        {
            int sbmax=0;
        int sbmin=nums[right];
        for(int i=left;i<=right;i++)
        {
            sbmin=min(sbmin,nums[i]);
            sbmax=max(sbmax,nums[i]);
        }        
        while(left>=0)
        {
            if(sbmin<nums[left])
                left--;
            else
                break;
        }
        while(right<nums.size())
        {
            if(sbmax>nums[right])
                right++;
            else
                break;
        }       
        return right-left-1;
        }
        return 0;
    }
};