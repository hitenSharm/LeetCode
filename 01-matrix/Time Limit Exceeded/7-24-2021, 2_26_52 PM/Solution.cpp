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
    
    int bfs(vector<vector<int>>& matrix,int& i,int& j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        int lvl=0;
        int ans=INT_MAX;
        while(!q.empty())
        {
            int len=q.size();
            for(int k=0;k<len;k++)
            {
              pair<int,int>temp=q.front();
              q.pop();
              int x=temp.first,y=temp.second;
              if(matrix[x][y]==0)
              {
                  return dp[i][j]=ans=min(ans,lvl);                  
              }
              if(isSafe(matrix,x+1,y))
              {
                  if(dp[x+1][y]==-1)q.push({x+1,y});
                  else
                  ans=min(ans,dp[x+1][y]+lvl+1);
              }
              if(isSafe(matrix,x-1,y))
              {
                  if(dp[x-1][y]==-1)q.push({x-1,y});
                  else
                  ans=min(ans,dp[x-1][y]+lvl+1);
              }
              if(isSafe(matrix,x,y+1))
              {
                  if(dp[x][y+1]==-1)q.push({x,y+1});
                  else
                  ans=min(ans,dp[x][y+1]+lvl+1);
              }
              if(isSafe(matrix,x,y-1))
              {
                  if(dp[x][y-1]==-1)q.push({x,y-1});
                  else
                  ans=min(ans,dp[x][y-1]+lvl+1);
              }
            }
            lvl++;
        }
        return dp[i][j]=ans;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>ans;
        dp.resize(mat.size(),vector<int>(mat[0].size(),-1));
        for(int i=0;i<mat.size();i++)
        {
            vector<int>temp;
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==0)
                temp.push_back(0);
                else
                temp.push_back(bfs(mat,i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};