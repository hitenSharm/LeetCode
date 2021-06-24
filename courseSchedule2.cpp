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
    
    bool cycelDetection(int index,vector<int>&vis)
    {
        if(vis[index]==1)
        return true;
        
        vis[index]=1;
        vector<int>candidates=adjList[index];
        for(int i=0;i<candidates.size();i++)
        {
            if(cycelDetection(candidates[i],vis))
            return true;
        }
        vis[index]=0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++)
        {
            if(cycelDetection(i,vis))
            return {};              
        }
        fill(vis.begin(),vis.end(),0); 
        for(int i=0;i<numCourses;i++)
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
        reverse(sol.begin(),sol.end());
        return sol;
    }
};