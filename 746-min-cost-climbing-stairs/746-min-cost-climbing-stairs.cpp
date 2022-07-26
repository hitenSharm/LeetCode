class Solution {
public:
    
    int recu(vector<int>& cost,int curr,vector<int>& dp)
    {
        if(curr>=cost.size())return 0;        
        if(dp[curr]!=-1)return dp[curr];
        int t1=cost[curr]+recu(cost,curr+1,dp);
        int t2=(curr+1<cost.size() ? cost[curr+1] : 0) + recu(cost,curr+2,dp);
        return dp[curr]=min(t1,t2);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return recu(cost,0,dp);
    }
};