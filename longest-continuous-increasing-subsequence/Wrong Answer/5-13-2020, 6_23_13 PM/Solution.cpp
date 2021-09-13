// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int c=1;
        int maxi=0;
      
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
            {
                c++;
                
            }
            if(maxi<c&&nums[i]>nums[i+1])
            {
                
                maxi=c;
                c=1;
            }
        }
        return maxi;
    }
};