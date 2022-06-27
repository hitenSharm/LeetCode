class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)return ;
        int i=1;
        int lastPeak=-1;
        while(i<nums.size())
        {
            if(nums[i]>nums[i-1])lastPeak=i;
            
            i++;
        }
        if(lastPeak==-1)
        {
            int i=0,j=nums.size()-1;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            return ;
        }
        int ending=nums.size()-1;
        for(int i=ending;i>=lastPeak;i--)
        {
            if(nums[i]>nums[lastPeak-1])
            {
                swap(nums[i],nums[lastPeak-1]);
                break ;
            }
        }
        int j=nums.size()-1;
        for(int i=lastPeak;i<j;i++)
        {
            swap(nums[i],nums[j]);
            j--;
        }
    }
};