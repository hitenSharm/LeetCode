// https://leetcode.com/problems/swim-in-rising-water

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:

    int n;
    vector<vector<int>>vis;
    int dirs[5]={1,0,-1,0,1};
    
    int dfs(vector<vector<int>>grid,int i,int j)
    {
      if(i==n-1 and j==n-1)
      return 1;

      if(vis[i][j]==1 || grid[i][j]==-1)
      return 0;

      vis[i][j]=1;
      int ans=0;
      for(int dir=0;dir<4;dir++)
      {
        int k=dirs[dir],k2=dirs[dir+1];
        if(i+k>=0 and i+k<n and j+k2>=0 and j+k2<n and vis[i+k][j+k2]==0 and grid[i+k][j+k2]!=-1)
        {          
          ans=dfs(grid,i+k,j+k2);
          if(ans==1)
          break;
        }
      }
      vis[i][j]=0;
    return ans;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        vis.resize(n,vector<int>(n,0));
        int l=1,r=50*49;
        int sol=INT_MAX;
        while(l<=r)
        {
          int m=l+(r-l)/2;
          vector<vector<int>>dfsGrid(n,vector<int>(n,0));
          for(int i=0;i<n;i++)
          {
            for(int j=0;j<n;j++)
            {
              if(grid[i][j]>m)
              dfsGrid[i][j]=-1;
              else
              dfsGrid[i][j]=grid[i][j];
            }
          }
          int ans=dfs(dfsGrid,0,0);
          if(ans==1)
          {
            sol=min(sol,m);
            r=m-1;
          }
          else
          l=m+1;
        }
      return sol;
    }
};