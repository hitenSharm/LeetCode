// https://leetcode.com/problems/jump-game

class Solution {
public:
    
    int memoise(vector<int>&nums,vector<int>&dp,int curr,int fin)
    {
        
        if(curr>=fin)
        {
          return 0;
        }               
        if(dp[curr]!=-1)
            return dp[curr];
        if(nums[curr]==0)
            return 1;
        int t1=memoise(nums,dp,nums[curr]+curr,fin);
        int t2=memoise(nums,dp,curr+1,fin);
        
        dp[curr]=min(t1,t2);
        
        if(dp[curr]==0)
            return 0;
        else
            return 1;
        
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size()==0)
            return true;
        int currIndex=0;
        int finalIndex=nums.size()-1;
        vector<int>dp(nums.size());
        fill(dp.begin(),dp.end(),-1);
        
        int temp= memoise(nums,dp,currIndex,finalIndex);
        if(temp==0)
            return true;
        return false;
    }
};