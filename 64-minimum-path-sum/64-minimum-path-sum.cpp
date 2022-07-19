class Solution {
public:
    
    vector<vector<int>>dp;
    
    bool valid(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size())return false;
        return true;
    }
    
    int recu(vector<vector<int>>& grid,int i,int j)
    {
        if(i==grid.size()-1 and j==grid[0].size()-1)return grid[i][j];
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=INT_MAX;
        if(valid(grid,i+1,j))
            ans=min(ans,grid[i][j]+recu(grid,i+1,j));
        if(valid(grid,i,j+1))
            ans=min(ans,grid[i][j]+recu(grid,i,j+1));
        
        return dp[i][j]=ans;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),-1));
        return recu(grid,0,0);
    }
};