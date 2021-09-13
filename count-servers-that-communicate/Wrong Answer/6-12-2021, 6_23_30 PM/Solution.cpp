// https://leetcode.com/problems/count-servers-that-communicate

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

    int vis[251][251];
    int safe(int i,int j,vector<vector<int>>& grid)
    {
      if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || vis[i][j]==1 || grid[i][j]==0)
        return 0;
      return 1;
    }
    int dfs(vector<vector<int>>& grid,int i,int j)
    {      
      vis[i][j]=1;
      int ans=1;
      if(safe(i+1,j,grid)==1)
        ans+=dfs(grid,i+1,j);
      if(safe(i-1,j,grid)==1)
        ans+=dfs(grid,i-1,j);
      if(safe(i,j+1,grid)==1)
        ans+=dfs(grid,i,j+1);
      if(safe(i,j-1,grid)==1)
        ans+=dfs(grid,i,j-1);
      return ans;
    }

    int countServers(vector<vector<int>>& grid) {
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[0].size();j++)
          {
            if(vis[i][j]==1 || grid[i][j]==0)continue;
            int x=dfs(grid,i,j);
            if(x>1)
                ans+=x;
          }
        }
        return ans;
    }
};