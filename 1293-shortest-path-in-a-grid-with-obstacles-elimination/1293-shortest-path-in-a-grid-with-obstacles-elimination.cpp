class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        queue<vector<int>>q;
        q.push({0,0,k});
        int steps=0;
        int dirs[5]={-1,0,1,0,-1};
        grid[0][0]=2;
        int m=grid.size()-1;
        int n=grid[0].size()-1;
        int vis[41][41][41*41];
        memset(vis,-1,sizeof(vis));
        vis[0][0][k]=1;
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                vector<int>temp=q.front();
                q.pop();
                int i=temp[0];
                int j=temp[1];
                int tk=temp[2];
                if(i==m and j==n)return steps;
                for(int x=0;x<4;x++)
                {
                    int ni=i+dirs[x];
                    int nj=j+dirs[x+1];
                    if(ni>=0 and nj>=0 and ni<grid.size() and nj<grid[0].size() and vis[ni][nj][tk]==-1)
                    {
                        if(grid[ni][nj]==1 and tk>0)
                        {
                            vis[ni][nj][tk]=1;
                            if(ni==m and nj==n)return steps+1;
                            q.push({ni,nj,tk-1});
                        }
                        if(grid[ni][nj]==0)
                        {
                            vis[ni][nj][tk]=1;
                            if(ni==m and nj==n)return steps+1;
                            q.push({ni,nj,tk});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};