// https://leetcode.com/problems/unique-paths

class Solution {
public:
    
    int dfs(int x,int y, int tarx,int tary,vector<vector<int>> &dp){
        
        if(x>tarx||y>tary)
            return 0;
        
        if(dp[y][x]!=-1)
            return dp[y][x];
        
        if(x==tarx&&y==tary)
        {           
            return 1;
        }
        int t1=dfs(x+1,y,tarx,tary,dp);
        int t2=dfs(x,y+1,tarx,tary,dp);
        if(dp[y][x]==-1)
        {
            return dp[y][x]=t1+t2;
        }
        else
        {
            return dp[y][x]=dp[y][x]+t1+t2;
        }
    }
    
    int uniquePaths(int m, int n) {        
        vector<int> row(n, -1);
        vector<vector<int>> dp(m, row) ;        
        int x=0;
        int y=0;
        int targetX=n-1;
        int targetY=m-1;
       int ans = dfs(x,y,targetX,targetY,dp);
        return ans;
    }
};