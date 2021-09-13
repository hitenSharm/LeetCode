// https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {        
        if(nums.size()==1)return 0;
        int prev=0;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]+prev;            
            prev=nums[i];
        }        
        if(nums[nums.size()-1]-nums[0]==0)return 0;        
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[nums.size()-1]-nums[i]==nums[i-1])return i;
        }
        if(nums[nums.size()-2]==0)return (nums.size()-1);
        return -1;
    }
};