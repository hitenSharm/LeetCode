class Solution {
public:
    int dp[2501][2501];
    int recu(int prev,int i,vector<int>& nums)
    {
        if(i>=nums.size())return 0;
        if(dp[prev+1][i]!=-1)return dp[prev+1][i];
        int ans=recu(prev,i+1,nums);
        if(prev==-1 || nums[prev]<nums[i])
            ans=max(ans,1+recu(i,i+1,nums));
        
        return dp[prev+1][i]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recu(-1,0,nums);
    }
};