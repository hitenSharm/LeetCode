// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

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
    unordered_map<int,vector<vector<int>>>adjList;
    unordered_map<int,int>cities;
    
    int dfs(int index,unordered_set<int>& vis,int& thresh,int dist)
    {      
      vis.insert(index);
      int ans=0;
      vector<vector<int>>candidates=adjList[index];
      for(int i=0;i<candidates.size();i++)
      {
        if(dist+candidates[i][1]<=thresh and vis.find(candidates[i][0])==vis.end())
        {          
          ans=ans + 1 + dfs(candidates[i][0],vis,thresh,dist+candidates[i][1]);
        }
      }
      return ans;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i=0;i<edges.size();i++)
        {
          adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          adjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }        
        unordered_set<int>vis;
        for(int i=0;i<n;i++)
        {          
          cities[i]=dfs(i,vis,distanceThreshold,0);
          vis.clear();
        }
        int mini=INT_MAX,city=INT_MIN;
        for(auto i:cities)
        {          
          if(i.second<mini)
          {
            mini=i.second;
            city=i.first;
          }
          if(i.second==mini)
            city=max(city,i.first);
        }
        return city;
    }
};