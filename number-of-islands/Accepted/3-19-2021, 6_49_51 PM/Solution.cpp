// https://leetcode.com/problems/number-of-islands

class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int i,int j)
    {
        if(j < grid[0].size() && i < grid.size() && i >= 0 && j >= 0)
        {
            if(grid[i][j]=='0')
                return;
                grid[i][j]='0';
                dfs(grid,i+1,j);
                dfs(grid,i,j+1);
                dfs(grid,i,j-1);
                dfs(grid,i-1,j);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {        
        vector<int>col(grid[0].size(),0);
        vector<vector<int>>vis(grid.size(),col);
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                char x=grid[i][j];
                if(x!='0')
                {                                     
                    cnt++;
                    dfs(grid,i,j);                                        
                }
            }           
        }
        return cnt;
    }
};