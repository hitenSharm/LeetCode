// https://leetcode.com/problems/max-area-of-island

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

    int dfs(vector<vector<int>>& grid,int i,int j)
    {
      if(i>=grid.size() || j>=grid[i].size() || i<0 || j<0 || grid[i][j]==0)
        return 0;
      grid[i][j]=0;
      return (1+dfs(grid,i+1,j)+dfs(grid,i,j+1)+dfs(grid,i-1,j)+dfs(grid,i,j-1));
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[i].size();j++)
          {
            if(grid[i][j]==1)
              maxi=max(maxi,dfs(grid,i,j));                      
          }
        }
        return maxi;
    }
};