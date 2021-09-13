// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        int maxsofar=0;
        int maxall=0;
        int neg=0;
        int mintill=-10000;
        for(int i=0;i<nums.size();i++){ 
        maxsofar=maxsofar+nums[i];
            if(maxsofar<0)maxsofar=0;
            if(nums[i]<0){    
                neg++;
                if(mintill<nums[i])
                    mintill=nums[i];
            }
            maxall=max(maxsofar,maxall);
        
        }
        if(neg==nums.size())
            return mintill;
        return maxall;
    }
};