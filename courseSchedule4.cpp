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

    unordered_map<int,vector<int>>adjList;
    int dp[101][101];
    
    int recu(int st,int en)
    {
        if(st==en)return 1;
        if(dp[st][en]!=-1)return dp[st][en];
        
        int ans=0;
        vector<int>& candidates=adjList[st];
        for(int i=0;i<candidates.size();i++)
        {
            ans=max(ans,recu(candidates[i],en));
            if(ans==1)break;
        }
        return dp[st][en]=ans;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool>ans;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<prerequisites.size();i++)
        {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<queries.size();i++)
        {
            int temp=recu(queries[i][0],queries[i][1]);
            if(temp==1)
            ans.push_back(true);
            else
            ans.push_back(false);
        }
        return ans;
    }
};