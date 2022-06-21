class Solution {
public:
    int dirs[5]={-1,0,1,0,-1};
    
    void recu(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)return ;
        grid[i][j]=2;
        for(int k=0;k<4;++k)
        recu(i+dirs[k],j+dirs[k+1],grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i)
        {
            if(grid[i][0]==1)recu(i,0,grid);                        
            if(grid[i][grid[0].size()-1]==1)recu(i,grid[0].size()-1,grid);            
        }
        for(int j=0;j<grid[0].size();++j)
        {
            if(grid[0][j]==1)recu(0,j,grid);
            if(grid[grid.size()-1][j]==1)recu(grid.size()-1,j,grid);
        }
        int ans=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            if(grid[i][j]==1)ans++;
        }
        return ans;
    }
};