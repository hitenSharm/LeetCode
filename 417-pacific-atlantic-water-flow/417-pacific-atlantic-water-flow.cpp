class Solution {
public:

    vector<vector<int>> bfs(vector<vector<int>>& ht,int toAdd)
    {
        int dirs[5]={-1,0,1,0,-1};
        
        queue<pair<int,int>>q;
        
        vector<vector<int>>mark(ht.size(),vector<int>(ht[0].size(),-1));
        
        if(toAdd==1)
        {
            for(int i=0;i<ht.size();i++)
            {
                q.push({i,0});
                mark[i][0]=1;
            }
            for(int j=1;j<ht[0].size();j++)
            {
                q.push({0,j});
                mark[0][j]=1;
            }
        }
        else
        {
            for(int i=ht.size()-1;i>=0;i--)
            {
                q.push({i,ht[0].size()-1});
                mark[i][ht[0].size()-1]=1;
            }
            for(int j=ht[0].size()-2;j>=0;j--)
            {
                q.push({ht.size()-1,j});
                mark[ht.size()-1][j]=1;
            }
        }
        
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first,j=p.second;            
            int curr=ht[i][j];
            for(int k=0;k<4;k++)
            {
                int ni=i+dirs[k];
                int nj=j+dirs[k+1];
                if(ni>=0 and nj>=0 and ni<ht.size() and nj<ht[0].size() and ht[ni][nj]>=curr and mark[ni][nj]==-1)
                {
                    mark[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }
        return mark;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        vector<vector<int>> pf = bfs(heights,1);
        vector<vector<int>> atl = bfs(heights,2);
        
        vector<vector<int>>ans;
        
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(pf[i][j]==atl[i][j] and pf[i][j]==1)ans.push_back({i,j});
            }
        }
        return ans;
    }
};