// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsofar=0;
        int maxall=0;
        for(int i=0;i<nums.size();i++){ 
        maxsofar=maxsofar+nums[i];
            if(maxsofar<0)maxsofar=0;
            
            maxall=max(maxsofar,maxall);
        
        }
        return maxall;
    }
};