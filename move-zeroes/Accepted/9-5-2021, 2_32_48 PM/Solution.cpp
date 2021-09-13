// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=1;
        while(i<nums.size() and j<nums.size())
        {
            if(i>=j)j=i+1;
            while(j<nums.size() and nums[j]==0)j++;
            if(nums[i]==0 and j<nums.size())swap(nums[i],nums[j]);
            i++;
        }
    }
};