class Solution {
public:
    vector<vector<int>>dp;
    bool sumK(vector<int>& nums,int t,int i)
    {
        if(t==0)return true;
        if(i>=nums.size() || t<0)return false;
        
        if(dp[i][t]!=-1)return dp[i][t]==1 ? true : false;
        
        bool ans=sumK(nums,t,i+1);
        ans=ans || sumK(nums,t-nums[i],i+1);
        if(ans)dp[i][t]=1;
        else
            dp[i][t]=0;
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0;
        for(auto i:nums)s+=i;
        if(s%2!=0)return false;
        dp.resize(nums.size(),vector<int>(s/2+1,-1));
        return sumK(nums,s/2,0);
    }
};