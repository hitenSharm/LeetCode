class Solution {
public:
    
    int recu(vector<vector<int>>& costs,int index,int color,vector<vector<int>>& dp)
    {
        if(index>=costs.size())return 0;
        if(color!=-1 and dp[index][color]!=-1)return dp[index][color];
        int ans=INT_MAX;
        for(int i=0;i<3;i++)
        {
            if(i==color)continue ;
            ans=min(ans,costs[index][i] + recu(costs,index+1,i,dp));
        }
        if(color==-1)
        return ans;
        
        return dp[index][color]=ans;
    }
    
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>>dp(costs.size(),vector<int>(3,-1));
        return recu(costs,0,-1,dp);
    }
};