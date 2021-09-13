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
    int dfs(vector<vector<int>>& grid,int i,int j)
    {      
      vis[i][j]=1;
      int ans=1;
      for(int k=0;k<grid[0].size();k++)
      {
        if(vis[i][k]==0 and grid[i][k]==1)
        {
          ans=ans+dfs(grid,i,k);
        }
      }
      for(int k=0;k<grid.size();k++)
      {
        if(vis[k][j]==0 and grid[k][j]==1)
        {
          ans=ans+dfs(grid,k,j); 
        }
      }
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