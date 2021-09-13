// https://leetcode.com/problems/possible-bipartition

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

    unordered_map<int,int>ump;
    unordered_map<int,vector<int>>adjList;
    vector<int>vis;
    
    bool bfs(int st)
    {
        queue<int>ind;
        int start=st;
        ind.push(start);
        int curr=0;
        ump[start]=0;
        while(!ind.empty())
        {
            start=ind.front();
            ind.pop();
            curr=ump[start];
            int comple=1;
            if(curr==1)comple=0;
            
            if(vis[start]==1)continue;
            
            vis[start]=1;
            ump[start]=curr;
            vector<int>candidates=adjList[start];
            for(int i=0;i<candidates.size();i++)
            {
                if(vis[candidates[i]]==1)continue;
                if(ump.find(candidates[i])!=ump.end() and ump[candidates[i]]!=comple)
                {                    
                    return false;
                }                                
                else
                {
                    ind.push(candidates[i]);
                    ump[candidates[i]]=comple;                                        
                }
            }            
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vis.resize(n+1,0);
        
        for(int i=0;i<dislikes.size();i++)
        {
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }        
        
       for(auto it:adjList)
        {
            if(bfs(it.first))
            return true;
            else
            {
                fill(vis.begin(),vis.end(),0);
                ump.clear();
            }
        }
       return false; 
    }
};