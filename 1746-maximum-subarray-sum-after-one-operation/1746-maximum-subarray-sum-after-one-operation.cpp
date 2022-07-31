class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        //index pe square kar rha or index pe square nahi kar rha
        vector<vector<int>>dp(nums.size(),vector<int>(2,0));
        dp[0][0]=nums[0];
        dp[0][1]=nums[0]*nums[0]; //square at that index
        int ans=0;
        for(int i=1;i<nums.size();i++)
        {
            if(dp[i-1][0]+nums[i]<0)dp[i][0]=0;
            else
                dp[i][0]=dp[i-1][0]+nums[i];
            dp[i][1]=max(dp[i-1][0]+(nums[i]*nums[i]),dp[i-1][1] + nums[i]);            
        }
        for(int i=0;i<dp.size();i++)
            ans=max(ans,max(dp[i][0],dp[i][1]));
        // cout<<endl;
        // for(int i=0;i<dp.size();i++)
        //     cout<<dp[i][1]<<" ";
        return ans;
    }
};