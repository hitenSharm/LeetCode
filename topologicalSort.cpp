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
    //topological sort
    unordered_map<int, vector<int>>adjList;
    vector<int>vis;
    stack<int>st;

    void dfs(int start)
    {
        vis[start]=1;
        vector<int>candidates=adjList[start];
        for(int i=0;i<candidates.size();i++)
        {
            if(vis[candidates[i]]==1)continue;
            dfs(candidates[i]);
        }
        st.push(start);
    }

    vector<int> findOrder(int numberOfNodes, vector<vector<int>>& makeAdjListFromArray) {
        vis.resize(numberOfNodes,0);
        
        for(int i=0;i<makeAdjListFromArray.size();i++)
        {
            adjList[makeAdjListFromArray[i][0]].push_back(makeAdjListFromArray[i][1]);
        }
        
        for(int i=0;i<numberOfNodes;i++)
        {
            if(vis[i]==1)continue;
            dfs(i);
        }
        vector<int>sol;
        while(!st.empty())
        {
            sol.push_back(st.top());
            st.pop();
        }
        return sol;
    }
};