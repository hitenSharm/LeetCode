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

    int dirs[5]={-1,0,1,0,-1};
    void recu(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1')return ;
        grid[i][j]='0';       
        for(int k=0;k<4;++k) 
        {
            recu(grid,i+dirs[k],j+dirs[k+1]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    recu(grid,i,j);
                }
            }
        }
        return ans;
    }
};