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

    vector<int>vis;
    vector<int>memo; //as nodes will be repeated
    unordered_map<int, vector<int>>adjList;
    
    int dfs(int index)
    {
        
        if(vis[index]==1)
        return 1;
        
        if(memo[index]!=-1)
        return memo[index];
        
        vis[index]=1;
        vector<int>candidates=adjList[index];
        int ans=0;
        
        for(int i=0;i<candidates.size();i++)
        {
            ans=dfs(candidates[i]);
            if(ans==1)break;
        }
        
        vis[index]=0;
        return memo[index]=ans;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vis.resize(numCourses,0);
        memo.resize(numCourses,-1);
        for(int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int ans=0;
        for(int i=0;i<numCourses;i++)
        {
            ans=dfs(i);
            if(ans==1)
            return false;
        }
        return true;
    }
}; 