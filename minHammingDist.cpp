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
    unordered_set<int>vis;
    vector<int> curr; 
    
    void dfs(int s)
    {
        if(vis.find(s)==vis.end())
        {
            vis.insert(s);
            curr.push_back(s);
            vector<int>& candids=adjList[s];
            for(int i=0;i<candids.size();i++)
            {
                dfs(candids[i]);
            }
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        for(int i=0;i<allowedSwaps.size();i++)
        {
            adjList[allowedSwaps[i][0]].push_back(allowedSwaps[i][1]);
            adjList[allowedSwaps[i][1]].push_back(allowedSwaps[i][0]);
        }
        int ham=0;
        for(int i=0;i<source.size();i++)
        {
            if(vis.find(i)!=vis.end())continue;
            curr=vector<int> ();
            dfs(i);
            unordered_map<int,int>ump;
            for(auto c:curr)ump[source[c]]++;
            for(auto c:curr)
            {
                if(ump[target[c]]<1)ham++;
                else
                ump[target[c]]--;
            }
        }
        return ham;
    }
};