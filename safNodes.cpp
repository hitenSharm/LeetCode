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
    vector<int>dp;
    vector<int>vis;

    int recu(vector<vector<int>>& graph,int index)
    {      
      if(index>=graph.size() || graph[index].size()==0)
        return 0;
      if(dp[index]!=-1)
        return dp[index];
      if(vis[index]==1)
        return 1;
      vis[index]=1;
      int ans=0;
      for(int i=0;i<graph[index].size();i++)
      {
        ans=max(ans,recu(graph,graph[index][i]));
        if(ans==1)
        {
          return dp[index]=1;
        }
      }
      return dp[index]=0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        dp.resize(graph.size(),-1);
        vis.resize(graph.size(),0);
        vector<int>ans;
        for(int i=0;i<graph.size();i++)
        {
          if(recu(graph,i)==0)
            ans.push_back(i);
        }
        return ans;
    }
};
