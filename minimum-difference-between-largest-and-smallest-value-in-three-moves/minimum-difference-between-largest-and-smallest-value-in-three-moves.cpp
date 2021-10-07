class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=3)return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        for(int i=0;i<3;i++)
        {
            int b=3-(i+1);
            int bi=nums.size()-b-1;
            int f=i+1;            
            ans=min(ans,nums[bi]-nums[f]);
        }
        ans=min(ans,nums[nums.size()-4]-nums[0]);
        return ans;
    }
};