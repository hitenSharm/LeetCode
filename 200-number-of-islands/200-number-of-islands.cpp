class Solution {
public:
    
    void bfs(int i,int j,vector<vector<char>>& grid)
    {
        int dirs[5]={-1,0,1,0,-1};
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int ni=dirs[k]+p.first;
                int nj=dirs[k+1]+p.second;
                if(ni>=0 and nj>=0 and ni<grid.size() and nj<grid[0].size() and grid[ni][nj]=='1'){
                    grid[ni][nj]='0';
                    q.push({ni,nj});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='0')continue ;
                ans++;
                bfs(i,j,grid);
            }
        }
        return ans;
    }
};