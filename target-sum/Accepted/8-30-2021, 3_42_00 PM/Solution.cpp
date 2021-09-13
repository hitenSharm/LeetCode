// https://leetcode.com/problems/target-sum

class Solution {
public:
    int dp[2002][1001];
    
    int recu(vector<int>& nums,int s,int i,int& t)
    {
        if(i==nums.size())
        {
            if(s==t)return 1;
            else
            return 0;
        }
        if(dp[s+1001][i]!=-1)return dp[s+1001][i];
        
        int t1=recu(nums,s+nums[i],i+1,t);
        int t2=recu(nums,s-nums[i],i+1,t);
        return (dp[s+1001][i]=t1+t2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return recu(nums,0,0,target);        
    }
};