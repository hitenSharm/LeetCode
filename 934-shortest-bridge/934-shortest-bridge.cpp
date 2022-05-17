class Solution {
public:
	int dirs[5]={-1,0,1,0,-1};
	void dfs(vector<vector<int>>& g,int i,int j,queue<pair<int,int>>& q)
	{
		q.push({i,j});
		g[i][j]=2;
		for(int k=0;k<4;k++)
		{
			int ni=i+dirs[k],nj=j+dirs[k+1];
			if(ni>=0 and ni<g.size() and nj>=0 and nj<g.size() and g[ni][nj]==1)
			{
				dfs(g,ni,nj,q);
			}
		}
	}

    int shortestBridge(vector<vector<int>>& g) {
		queue<pair<int,int>>q;
        int fl=0;
        for(int i=0;i<g.size();i++)
		{
			for(int j=0;j<g.size();j++)
			{
				if(g[i][j]==1)
				{
					dfs(g,i,j,q);
					fl=1;
                    break;
				}
			}
            if(fl==1)break;
		}        
		int ans=0;
		while(!q.empty())
		{
			int len=q.size();
			for(int i=0;i<len;i++)
			{
				pair<int,int>&p=q.front();                
				for(int k=0;k<4;k++)
				{
					int ni=p.first+dirs[k],nj=p.second+dirs[k+1];
					if(ni>=0 and ni<g.size() and nj>=0 and nj<g.size())
					{
						if(g[ni][nj]==0)
                        {
                            q.push({ni,nj}); 
                            g[ni][nj]=2;
                        }
						if(g[ni][nj]==1)
						return ans;
					}
				}                
				q.pop();
			}
			ans++;
		}
        return ans;
    }
};