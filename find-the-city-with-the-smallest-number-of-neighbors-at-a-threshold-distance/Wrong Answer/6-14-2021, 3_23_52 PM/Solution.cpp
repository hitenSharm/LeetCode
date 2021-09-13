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
    
    int dijkstra(int index,unordered_set<int>& vis,int& thresh,int n)
    {            
      int ans=0;      
      int dist[101]={INT_MAX};
      dist[index]=0;
      priority_queue<pair<int,int>> q; 
      q.push({0,index});

      while(!q.empty())
      {
        int ind=q.top().second;
        q.pop();
        if(vis.find(ind)!=vis.end())
          continue;
        vis.insert(ind);
        vector<vector<int>>candidates=adjList[ind];
        for(int i=0;i<candidates.size();i++)
        {
          int newCandid=candidates[i][0],newDist=candidates[i][1];
          if(dist[newCandid]>dist[ind]+newDist)
          {
            dist[newCandid]=dist[ind]+newDist;
            q.push({dist[newCandid],newCandid});
          }
        }
      }
      for(int i=0;i<n;i++)
      {
        if(i!=index and dist[i]<=thresh)
        {
          ans++;
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
          cities[i]=dijkstra(i,vis,distanceThreshold,n);
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