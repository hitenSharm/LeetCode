// https://leetcode.com/problems/unique-paths-ii

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

    int ans=0;
    int dirs[3]={1,0,1};
    
    void recu(vector<vector<int>>& obstacleGrid,int i,int j)
    {
        if(i==obstacleGrid.size()-1 and j==obstacleGrid[0].size()-1)
        {
            ans++;
            return ;
        }
        for(int k=0;k<2;k++)
        {
            int newI=i+dirs[k],newJ=j+dirs[k+1];
            if(newI>=0 and newI<obstacleGrid.size() and newJ>=0 and newJ<obstacleGrid[0].size() and obstacleGrid[newI][newJ]==0)
            {
                obstacleGrid[newI][newJ]=1;
                recu(obstacleGrid,newI,newJ);
                obstacleGrid[newI][newJ]=0;
            }
        }
        return ;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1 || obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1)return 0;
        obstacleGrid[0][0]=1;
        recu(obstacleGrid,0,0);
        return ans;
    }
};