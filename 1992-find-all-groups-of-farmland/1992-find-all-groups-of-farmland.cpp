class Solution {
public:
	int dirs[5]={-1,0,1,0,-1};
	void dfs(vector<vector<int>>& land,int& r,int& c,int i,int j)
	{
		land[i][j]=2;
		r=max(r,i);
		c=max(c,j);
		for(int k=0;k<4;k++)
		{
			int ni=i+dirs[k],nj=j+dirs[k+1];
			if(ni>=0 and nj>=0 and ni<land.size() and nj<land[0].size() and land[ni][nj]==1)
			{
				dfs(land,r,c,ni,nj);
			}
		}
	}

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
		for(int i=0;i<land.size();i++)
		{
			for(int j=0;j<land[0].size();j++)
			{
				if(land[i][j]==1)
				{
					vector<int>tmp={i,j};
					int r=i,c=j;
					dfs(land,r,c,i,j);
					tmp.push_back(r);
					tmp.push_back(c);
					ans.push_back(tmp);
				}
			}
		}
		return ans;
    }
};