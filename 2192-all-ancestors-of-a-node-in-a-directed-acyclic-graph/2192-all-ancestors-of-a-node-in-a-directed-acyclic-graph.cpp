class Solution {
public:
	void dfs(vector<vector<int>>& ans,int currNode,int parentNode,unordered_map<int,vector<int>>& adj,vector<int>& vis)
	{
		vector<int>& tmp=adj[currNode];
		vis[currNode]=1;
		for(int i=0;i<tmp.size();i++)
		{
			if(vis[tmp[i]]==0)
			{
				ans[tmp[i]].push_back(parentNode);
				dfs(ans,tmp[i],parentNode,adj,vis);
			}
		}
	}
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
		for(int i=0;i<edges.size();i++)
		adj[edges[i][0]].push_back(edges[i][1]);

		vector<vector<int>>ans(n);				
		for(int i=0;i<n;i++)
		{			
            vector<int>vis(n,0);
			dfs(ans,i,i,adj,vis);			
		}
		return ans;
    }
};