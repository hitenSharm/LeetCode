class Solution {
public:
    
    bool isGood(int i,vector<int>& nums)
    {
        if(i==0 || nums[i]>nums[i-1])return true;
        return false;
    }
    
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int isValid=0;
        while(j<nums.size() and nums[j]==nums[i])
        {
            j++;
        }
        while(j<nums.size() and i<nums.size())
        {
            if(j<i)j=i+1;
            if(isGood(i,nums))
            {
                isValid=i;
                i++;
            }
            else
            {                
                swap(nums[i],nums[j]);
                if(isGood(i,nums))isValid=i;
                j++;
            }            
        }
        return isValid+1;
    }
};