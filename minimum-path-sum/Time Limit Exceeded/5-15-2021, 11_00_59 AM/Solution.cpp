// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    
    int msum=INT_MAX;
    
    bool helper(int i,int j,vector<vector<int>> &grid)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==-1)
        {
            return false;
        }
        return true;
    }
    
    void backtrack(int sum,vector<vector<int>>& grid,int i,int j)
    {
        if(i==grid.size()-1 && j==grid[0].size()-1)
        {            
            msum=min(sum,msum);
            return ;
        }
        //gen candidates , make move , undo move
        if(helper(i+1,j,grid))
        {
            sum+=grid[i+1][j];
            int temp=grid[i+1][j];
            grid[i+1][j]=-1;
            backtrack(sum,grid,i+1,j);
            sum=sum-temp;
            grid[i+1][j]=temp;
        }
        if(helper(i,j+1,grid))
        {
            sum+=grid[i][j+1];
            int temp=grid[i][j+1];
            grid[i][j+1]=-1;
            backtrack(sum,grid,i,j+1);
            sum=sum-temp;
            grid[i][j+1]=temp;
        }        
    }


    int minPathSum(vector<vector<int>>& grid) {
        //need to implement dfs
        int sum=grid[0][0];
        grid[0][0]=-1;
        backtrack(sum,grid,0,0);
        return msum;
        
    }
};