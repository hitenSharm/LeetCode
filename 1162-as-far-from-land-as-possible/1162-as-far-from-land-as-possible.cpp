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
    
    int maxDistance(vector<vector<int>>& grid) {                
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[i].size();++j)
            {
                if(grid[i][j]==1)q.push({i,j});
            }
        }
        if(q.size()==0 || q.size() == (grid.size()*grid[0].size()))return -1;
        int level=1;
        int ans=0;
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;++i)
            {
                pair<int,int>& p=q.front();                
                for(int k=0;k<4;++k)
                {
                    int ni=p.first+dirs[k],nj=p.second+dirs[k+1];                    
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 0) {
					q.push({ ni, nj });
					grid[ni][nj] = level;
					ans = max(ans, level);
				}
                }                
                q.pop();
            }
            level++;
        }
        return ans;
    }
};