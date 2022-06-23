class Solution {
public:

    vector<int>dp;
    int recu(int i,vector<int>& nums)
    {
        if(i>=nums.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=100001;
        for(int j=1;j<=nums[i];++j)
        {
            ans=min(ans,1+recu(i+j,nums));
        }
        return dp[i]=ans;
    }

    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return recu(0,nums);
    }
};