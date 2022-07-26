class Solution {
public:
    
//     int recu(vector<vector<int>>& costs,int index,int color,vector<vector<int>>& dp)
//     {
//         if(index>=costs.size())return 0;
//         if(color!=-1 and dp[index][color]!=-1)return dp[index][color];
//         int ans=INT_MAX;
//         for(int i=0;i<3;i++)
//         {
//             if(i==color)continue ;
//             ans=min(ans,costs[index][i] + recu(costs,index+1,i,dp));
//         }
//         if(color==-1)
//         return ans;
        
//         return dp[index][color]=ans;
//     }
    
    int minCost(vector<vector<int>>& costs) {
        
        for(int i=1;i<costs.size();i++)
        {
            costs[i][0]=costs[i][0]+min(costs[i-1][1],costs[i-1][2]);
            costs[i][1]+=min(costs[i-1][0],costs[i-1][2]);
            costs[i][2]+=min(costs[i-1][0],costs[i-1][1]);
        }
        int n=costs.size()-1;
        return min(costs[n][0],min(costs[n][1],costs[n][2]));
    }
};