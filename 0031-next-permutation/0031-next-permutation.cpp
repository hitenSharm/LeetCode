class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)return ;
        int i=nums.size()-2;
        while(i>=0 and nums[i]>=nums[i+1])i--;
        if(i>=0)
        {
            int j=nums.size()-1;
            while(nums[j]<=nums[i])j--; //find first from back after peak which is bigger
            swap(nums[i],nums[j]);
            j=nums.size()-1;
            i=i+1;
            while(j>=i)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
        }
        else
        {
            reverse(nums.begin(),nums.end());
        }
    }
};