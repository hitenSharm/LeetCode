// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int s=accumulate(nums.begin(),nums.end(),0);        
        int i=0,j=0;
        x=s-x;
        if(x==0)return nums.size();
        if(x<0)return -1;
        int len=0;
        int stillhere=0;
        while(i<nums.size())
        {
            if(i>j)j=i+1;
            while(stillhere<x and j<nums.size())
            {
                stillhere+=nums[j];
                j++;
            }
            if(stillhere==x)len=max(len,j-i);
            stillhere-=nums[i];
            i++;
        }
         
        if(len==0)return -1;
        return nums.size()-len;
    }
};