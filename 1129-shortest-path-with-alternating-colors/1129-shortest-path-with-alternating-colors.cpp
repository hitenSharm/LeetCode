class Solution {
public:

	void bfs(unordered_map<int,vector<int>>& adj,vector<vector<int>>& dist,queue<pair<int,int>>& q,int& curr,int rb)
	{
		vector<int>& tmp=adj[curr];
		int nrb;
		if(rb==0)nrb=1;
		if(rb==1)nrb=0;
		for(int i=0;i<tmp.size();i++)
		{
			if(dist[tmp[i]][rb]==INT_MAX)
			{
				dist[tmp[i]][rb]=1+dist[curr][nrb];
				q.push({tmp[i],rb});
			}
		}
	}

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
       unordered_map<int,vector<int>>adjBlue;
	   unordered_map<int,vector<int>>adjRed; 
	   for(int i=0;i<blueEdges.size();i++)
	   {
		   adjBlue[blueEdges[i][0]].push_back(blueEdges[i][1]);
	   }
	   for(int i=0;i<redEdges.size();i++)
	   {
		   adjRed[redEdges[i][0]].push_back(redEdges[i][1]);
	   }
	   queue<pair<int,int>>q;
	   q.push({0,-1});
	   vector<vector<int>>dist(n, vector<int> (2, INT_MAX));
	   dist[0][0]=dist[0][1]=0;
	   while(!q.empty())
	   {
		   pair<int,int> p=q.front();
		   q.pop();
		   int node=p.first,rb=p.second;
		   if(rb==-1)
		   {
			   bfs(adjBlue,dist,q,node,1);
			   bfs(adjRed,dist,q,node,0);
		   }	
		   else if(rb==1)
		   {
			   bfs(adjRed,dist,q,node,0);
		   }	
		   else
		   {
			   bfs(adjBlue,dist,q,node,1);
		   }
	   }
	   vector<int>ans(n,-1);
	   for(int i=0;i<n;i++)
	   {
		   ans[i]=min(dist[i][0],dist[i][1]);
		   if(ans[i]==INT_MAX)ans[i]=-1;
	   }
	   return ans;
    }
};