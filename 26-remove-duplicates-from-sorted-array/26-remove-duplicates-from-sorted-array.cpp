class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size())
        {
            int curr=nums[i];
            i++;
            while(i<nums.size() and curr==nums[i])
            {
                nums[i]=-101;
                i++;
            }
        }
        i=0;
        while(i<nums.size())
        {
            if(j<i)j=i;
            if(nums[i]!=-101)i++;
            else
            {                
                while(j<nums.size() and nums[j]==-101)j++;
                if(j<nums.size())
                swap(nums[i],nums[j]);
                i++;
            }
        }        
        i=0;
        while(i<nums.size() and nums[i]!=-101)
            i++;
        return i;
    }
};