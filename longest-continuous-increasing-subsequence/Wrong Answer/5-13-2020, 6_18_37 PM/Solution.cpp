// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int c=1;
        int maxi=1;
        
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
                c++;
            if(maxi<c)
            {
                maxi=c;
                c=0;
            }
        }
        return maxi;
    }
};