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
    bool isSafe(int i,int j,vector<vector<int>>& grid2)
    {
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size() || grid2[i][j]!=1)return false;
        
        return true;
    }
    int dirs[5]={-1,0,1,0,-1};
    void recu(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j,bool& ans)
    {
        if(i<0 || j<0 || i>=grid2.size() || j>=grid2[0].size() || grid2[i][j]!=1) return ;
        if(grid1[i][j]!=grid2[i][j])
        {
            ans=false;
            //if no return then i can mark the whole island in grid2 in 1 iteration
        }
        grid2[i][j]=2;
        for(int k=0;k<4;++k)
        {
            int ni=i+dirs[k],nj=j+dirs[k+1];
            recu(grid1,grid2,ni,nj,ans);
        }
        
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0;        
        for(int i=0;i<grid2.size();++i)
        {
            for(int j=0;j<grid2[0].size();++j)
            {
                if(grid2[i][j]==1)
                {
                    bool ans=true;
                    recu(grid1,grid2,i,j,ans);
                    if(ans)cnt++;
                }
            }
        }
        return cnt;
    }
};