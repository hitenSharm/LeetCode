class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch algo
        int l=0,r=nums.size()-1;
        int m=0;
        //all ele behind l are 0
        //all ele after r are 2
        while(m<=r)
        {
            if(nums[m]==0)
            {
                //should be on left of l
                swap(nums[l],nums[m]);
                l++;
                m++;
            }
            else if(nums[m]==2)
            {
                //with r
                swap(nums[m],nums[r]);
                r--;
            }
            else//m has 1
                m++;
        }
    }
};