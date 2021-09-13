// https://leetcode.com/problems/map-of-highest-peak

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

    vector<vector<int>>vis;
    
    bool isSafe(int i,int j,vector<vector<int>>& vis)
    {
      if(i>=0 and j>=0 and i<vis.size() and j<vis[0].size() and vis[i][j]==0)
        return true;
      return false;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {        
        vis.resize(isWater.size(),vector<int>(isWater[0].size(),0));        
        queue<vector<int>>bfs;
        for(int i=0;i<isWater.size();i++)
        {
          for(int j=0;j<isWater[0].size();j++)
          {
            if(isWater[i][j]==1)
            {
              isWater[i][j]=0;
              bfs.push({i,j});
            }
          }
        }
        int cnt=1;
        while(!bfs.empty())
        {
          int len=bfs.size();
          for(int k=0;k<len;k++)
          {
            vector<int>tmp=bfs.front();
            bfs.pop();
            int i=tmp[0],j=tmp[1];            
            vis[i][j]=1;
            if(isSafe(i+1,j,vis))
            {
              isWater[i+1][j]=cnt;
              bfs.push({i+1,j});
              vis[i+1][j]=1;
            } 
            if(isSafe(i-1,j,vis))
            {
              isWater[i-1][j]=cnt;
              bfs.push({i-1,j});
              vis[i-1][j]=1;
            } 
            if(isSafe(i,j+1,vis))
            {
              isWater[i][j+1]=cnt;
              bfs.push({i,j+1});
              vis[i][j+1]=1;
            } 
            if(isSafe(i,j-1,vis))
            {
              isWater[i][j-1]=cnt;
              bfs.push({i,j-1});
              vis[i][j-1]=1;
            }
          }
          cnt++;
        }
        return isWater;
    }
};