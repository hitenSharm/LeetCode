// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mini=2*nums.size();
        int maxi=0;
        int fl=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i+1]<nums[i] && fl==0)
            {
                mini=min(mini,i);
                maxi=max(maxi,i+1);
                fl=1;
                continue;
            }
            if(fl==1)
            {
                if(nums[i+1]<=nums[i])
                    maxi=i+1;
                else
                    fl=2;
                continue;
            }
            if(fl==2)
            {
                if(nums[i+1]<nums[i])
                {
                    maxi=i+1;
                    fl=1;
                }                
                continue;
            }
        }
        int ans=maxi-mini+1;
        if(ans>nums.size())
        {
            return 0;
        }
        else
            return maxi-mini+1;
    }
};