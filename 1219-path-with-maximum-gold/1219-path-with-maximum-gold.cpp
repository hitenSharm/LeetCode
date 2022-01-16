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
    int recu(vector<vector<int>> grid,int i,int j,int ans)
    {
        ans+=grid[i][j];
        grid[i][j]=0;
        int dirs[5]={0,1,0,-1,0};
        int tmp=ans;
        for(int k=0;k<4;k++)
        {  
            int ni=i+dirs[k],nj=j+dirs[k+1];
            if(ni>=grid.size() || nj>=grid[0].size() || ni<0 || nj<0 || grid[ni][nj]==0)continue;
            ans=max(ans,recu(grid,ni,nj,tmp));
        }
        return ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)continue;
                ans=max(ans,recu(grid,i,j,0));
            }
        }
        return ans;
    }
};