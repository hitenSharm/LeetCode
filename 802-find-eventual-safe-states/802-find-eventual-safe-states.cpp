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

	int dfs(vector<int>& vis,vector<int>& dp,unordered_map<int,vector<int>>& adj,int curr)
	{
        if(dp[curr]!=-1)return dp[curr];
		if(vis[curr]==1)return 1;		
		vis[curr]=1;
		vector<int>& tmp=adj[curr];
		int ans=0;
		for(int i=0;i<tmp.size();i++)
		{
			ans=max(ans,dfs(vis,dp,adj,tmp[i]));
			if(ans==1)return dp[curr]=1;
		}
		return dp[curr]=0;
	}

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
		vector<int>dp(n,-1);
		unordered_map<int,vector<int>>adj;
		for(int i=0;i<graph.size();i++)
		{
			for(int j=0;j<graph[i].size();j++)
			{
				adj[i].push_back(graph[i][j]);
			}
		}
		vector<int>ans;
		for(int i=0;i<n;i++)
		{
			if(dp[i]==-1)
			{
				vector<int>vis(n,0);
				dfs(vis,dp,adj,i);
			}
			if(dp[i]==0)ans.push_back(i);
		}
		return ans;
    }
};