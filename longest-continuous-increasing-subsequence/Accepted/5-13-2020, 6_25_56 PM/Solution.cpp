// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int c=1;
        int maxi=1;
      
        for(int i=1;i<nums.size();i++)
        {
             if(nums[i]>nums[i-1])
                c++;
            else c = 1 ;
            maxi = max(maxi,c);
        }
        return maxi;
    }
};