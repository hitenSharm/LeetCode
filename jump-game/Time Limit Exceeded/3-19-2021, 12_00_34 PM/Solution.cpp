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
        int t1=2;
        int x=nums[curr];
        while(x>0)
        {
            t1=min(t1,memoise(nums,dp,x+curr,fin));
            x--;
        }
        
        dp[curr]=t1;
        
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