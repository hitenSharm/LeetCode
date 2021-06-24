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

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vis.resize(n,0);
        unordered_map<int,vector<pair<int,double>>>adjList;
        
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back(make_pair(edges[i][1],succProb[i]));
            adjList[edges[i][1]].push_back(make_pair(edges[i][0],succProb[i]));
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1,start});
        vector<double>nodes(n,DBL_MIN);
        nodes[start]=1;
        while(!pq.empty())
        {
            start=pq.top().second;
            double dist=pq.top().first;
            pq.pop();
            if(vis[start]==1)continue;
            vis[start]=1;
            vector<pair<int,double>>& candid=adjList[start];
            for(int i=0;i<candid.size();i++)
            {
                double newDist=candid[i].second;
                if(newDist * dist > nodes[candid[i].first])
                {
                    nodes[candid[i].first]=newDist * dist;
                    pq.push({nodes[candid[i].first],candid[i].first});
                }
            }
            if(start==end)
            return nodes[start];
        }
        return 0;
    }
};