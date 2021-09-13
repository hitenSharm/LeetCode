// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>sorted=nums;
        sort(sorted.begin(),sorted.end());
        int maxi=0;
        int mini=2*nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(sorted[i]!=nums[i])
            {
                maxi=max(maxi,i);
                mini=min(mini,i);
            }
                
        }
        if(maxi-mini==-2*nums.size())
            return 0;
        else
            return maxi-mini+1;
    }
};