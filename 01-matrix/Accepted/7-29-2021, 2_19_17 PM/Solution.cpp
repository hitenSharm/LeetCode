// https://leetcode.com/problems/01-matrix

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

    vector<vector<int>>dp;
    
    bool isSafe(vector<vector<int>>& matrix,int x,int y)
    {
        if(x>=0 and y>=0 and x<matrix.size() and y<matrix[0].size())
        return true;
        
        return false;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {    
        //this method reduces the amount of times i need to apply bfs
        queue<pair<int,int>>q;        
        dp.resize(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        for(int i=0;i<mat.size();i++)
        {            
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j]=0;
                    q.push({i,j});
                }
            }            
        }
        
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            q.pop();
            int x=temp.first,y=temp.second;
            if(isSafe(mat,x+1,y) and dp[x+1][y]>dp[x][y]+1)
            {
                dp[x+1][y]=dp[x][y]+1;
                q.push({x+1,y});
            }
            if(isSafe(mat,x-1,y) and dp[x-1][y]>dp[x][y]+1)
            {
                dp[x-1][y]=dp[x][y]+1;
                q.push({x-1,y});
            }
            if(isSafe(mat,x,y+1) and dp[x][y+1]>dp[x][y]+1)
            {
                dp[x][y+1]=dp[x][y]+1;
                q.push({x,y+1});
            }
            if(isSafe(mat,x,y-1) and dp[x][y-1]>dp[x][y]+1)
            {
                dp[x][y-1]=dp[x][y]+1;
                q.push({x,y-1});
            }
        }
        
        return dp;
    }
};