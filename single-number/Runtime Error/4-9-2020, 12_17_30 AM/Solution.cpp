// https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums[0]!=nums[1])
            return nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(i<nums.size()-1)
            if(nums[i]!=nums[i+1]&&nums[i]!=nums[i-1])          
                return nums[i];
            if(i==nums.size()-1)
            {
                if(nums[i]!=nums[i-1])
                    return nums[i];
            }
        }
        return -1;
    }
};