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
	void dfs(vector<vector<int>>& isConnected,vector<int>& vis,int& n,int i)
	{
		vis[i]=1;
		for(int j=0;j<n;j++)
		{
			if(isConnected[i][j]==1 and i!=j and vis[j]==0)
			dfs(isConnected,vis,n,j);
		}
	}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
		vector<int>vis(n,0);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				ans++;
				dfs(isConnected,vis,n,i);
			}
		}
		return ans;
    }
};