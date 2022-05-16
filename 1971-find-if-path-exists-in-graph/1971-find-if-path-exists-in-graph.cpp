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
	unordered_set<int>vis;

	bool recu(int& c,int& d,unordered_map<int,vector<int>>& adjList)
	{
		if(c==d)return true;
		vis.insert(c);
		vector<int>& tmp=adjList[c];
		bool ans=false;
		for(int i=0;i<tmp.size();i++)
		{
			if(vis.find(tmp[i])==vis.end())
			{
				ans=ans||recu(tmp[i],d,adjList);
				if(ans)return ans;
			}
		}
		return ans;
	}

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adjList;
		for(int i=0;i<edges.size();i++)
		{
			adjList[edges[i][0]].push_back(edges[i][1]);
			adjList[edges[i][1]].push_back(edges[i][0]);
		}
		return recu(source,destination,adjList);
    }
};