class Solution {
public:
	typedef pair<int,pair<int,int>> pi;
	
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& ending) {
    	//djikstras but we keep rolling till we hit the fimnal node
		priority_queue<pi,vector<pi>,greater<pi>>pq;
		vector<vector<int>>dist(maze.size(),vector<int>(maze[0].size(),INT_MAX));
		set<pair<int,int>>vis;
		
		vis.insert({start[0],start[1]});
		dist[start[0]][start[1]]=0;
		pq.push({0,{start[0],start[1]}});
		
		int dirs[5]={-1,0,1,0,-1};
		
		while(!pq.empty())
		{
			pi p=pq.top();
			pq.pop();
			int curr=p.first;
			pair<int,int> p2=p.second;
			int ni=p2.first;
			int nj=p2.second;
			vis.insert({ni,nj});
			for(int k=0;k<4;k++)
			{
                int i=ni,j=nj;
				int ndist=0;
				while(i+dirs[k]>=0 and i+dirs[k]<maze.size() and j+dirs[k+1]>=0 and j+dirs[k+1]<maze[0].size() and maze[i+dirs[k]][j+dirs[k+1]]==0)
				{
					ndist++;
					i+=dirs[k];
					j+=dirs[k+1];
				}
				
				//if i ended up at an unvisited node
				if(vis.find({i,j})==vis.end())
				{
					if(curr+ndist<dist[i][j])
					{
						dist[i][j]=curr+ndist;
						pq.push({dist[i][j],{i,j}});
					}					
				}
			}			
		}        
		return dist[ending[0]][ending[1]]!=INT_MAX ? dist[ending[0]][ending[1]]: -1;
    }
};