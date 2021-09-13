// https://leetcode.com/problems/out-of-boundary-paths

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
    
    int dp[51][51][51];
    int maxiMoves;
    int dirs[5]={1,0,-1,0,1};
    
    int recu(int i,int j,int maxMoveFromHere,int& m,int &n)
    {
        if((i<0 || i>=m || j<0 || j>=n) and maxMoveFromHere<=maxiMoves)
        return 1;
        if(maxMoveFromHere<=0)
        return 0;
        if(dp[i][j][maxMoveFromHere]!=-1)
        return dp[i][j][maxMoveFromHere];
        
        int ans=0;
        
        for(int t=0;t<4;t++)
        {
            ans+=recu(i+dirs[t],j+dirs[t+1],maxMoveFromHere-1,m,n);
        }
        return dp[i][j][maxMoveFromHere]=ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i=0;i<51;i++)
        {
            for(int j=0;j<51;j++)
            {
                for(int k=0;k<51;k++)
                dp[i][j][k]=-1;
            }
        }
        maxiMoves=maxMove;
        int ans=recu(startRow,startColumn,maxMove,m,n);
        return ans;
    }
};