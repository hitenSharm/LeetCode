// https://leetcode.com/problems/pacific-atlantic-water-flow

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
    
    int dp[201][201];
    
    bool isSafe(int x,int y,vector<vector<int>>& heights,int& val)
    {
        if(x>=0 and y>=0 and x<heights.size() and y<heights[0].size() and heights[x][y]<=val)
        return true;
        
        return false;
    }

    void bfs(vector<vector<int>>& heights,int i,int j,vector<vector<int>>& ans)
    {
        queue<pair<int,int>>q;
        int vis[201][201];
        memset(vis,0,sizeof(vis));
        q.push({i,j});
        int pf=0,at=0;
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            q.pop();
            vis[temp.first][temp.second]=1;
            int val=heights[temp.first][temp.second];
            if(temp.first-1<0 || temp.second-1<0)
            pf=1;
            
            if(temp.first+1>=heights.size() || temp.second+1>=heights[0].size())
            at=1;
            
            int x=temp.first,y=temp.second;
            if(isSafe(x+1,y,heights,val) and vis[x+1][y]==0)q.push({x+1,y});
            if(isSafe(x-1,y,heights,val) and vis[x-1][y]==0)q.push({x-1,y});
            if(isSafe(x,y+1,heights,val) and vis[x][y+1]==0)q.push({x,y+1});
            if(isSafe(x,y-1,heights,val) and vis[x][y-1]==0)q.push({x,y-1});
            
            if((pf==1 and at==1) || dp[temp.first][temp.second]!=-1)
            {
                ans.push_back({i,j});
                dp[i][j]=1;
                return ;
            }
        }
        return ;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[i].size();j++)
            bfs(heights,i,j,ans);
        }
        return ans;
    }
};