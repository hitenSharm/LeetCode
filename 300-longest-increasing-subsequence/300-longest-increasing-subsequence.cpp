class Solution {
public:
    vector<int>dp;
    int recu(vector<int>& nums,int i)
    {
        if(i>=nums.size())return 0;
        int ans=1;
        if(dp[i]!=-1)return dp[i];
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]>nums[i])
            ans=max(ans,1+recu(nums,j));
        }
        return dp[i]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        dp.resize(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,recu(nums,i));            
        }
        return ans;
    }
};