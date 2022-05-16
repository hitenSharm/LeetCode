class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;        
		if(grid[0][0]==1)return -1;
        if(grid.size()==1)return 1;
		q.push({0,0});		
		int ans=1;
		int n=grid.size();
		vector<int> dirs{0,1,0,-1,0,1,1,-1,-1,1};
		while(!q.empty())
		{
			int len=q.size();
			for(int t=0;t<len;t++)
			{
				pair<int,int>& p=q.front();
				int i=p.first,j=p.second;				
				for(int k=0;k<9;k++)
				{
					if(i+dirs[k]>=0 and i+dirs[k]<n and j+dirs[k+1]>=0 and j+dirs[k+1]<n)
					{
						if(grid[i+dirs[k]][j+dirs[k+1]]==0)
                        {
                            q.push({i+dirs[k],j+dirs[k+1]});                            
                        }
						if(i+dirs[k]==n-1 and j+dirs[k+1]==n-1 and grid[n-1][n-1]==0)return ans+1;				
                        grid[i+dirs[k]][j+dirs[k+1]]=1;
					}
				}			
				q.pop();
			}
			ans++;
		}
		return -1;
    }
};