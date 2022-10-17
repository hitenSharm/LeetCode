class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            //l->m is sorted
            if(target==nums[m])return m;
            if(nums[l]<=nums[m])
            {
                //is in this range
                if(target>=nums[l] and target<=nums[m])
                {
                    r=m-1;
                }
                else
                    l=m+1;
            }
            else
            {
                //the other half is sorted
                if(target>=nums[m] and target<=nums[r])
                {
                    l=m+1;
                }
                else
                    r=m-1;
            }
        }
        return -1;
    }
};