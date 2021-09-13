// https://leetcode.com/problems/rotting-oranges

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
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int dirs[5]={1,0,-1,0,1};
        int lvl=0;        
        int rot=0,tot=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    rot++;
                }
                if(grid[i][j]==1||grid[i][j]==2)tot++;
            }
        }
        while(!q.empty())
        {
            int len=q.size();            
            for(int i=0;i<len;i++)
            {
              int currI=q.front().first,currJ=q.front().second;                
              q.pop();              
              for(int k=0;k<4;k++)
              {
                  int newI=currI+dirs[k],newJ=currJ+dirs[k+1];
                  if(newJ>=0 and newJ<grid[0].size() and newI>=0 and newI<grid.size() and grid[newI][newJ]==1)
                  {
                      grid[newI][newJ]=2;
                      rot++;
                      q.push({newI,newJ});
                  }
              }
            }
            if(q.size()==0)break;
            lvl++;
        }
        if(rot!=tot)return -1;
        return lvl;
    }
};