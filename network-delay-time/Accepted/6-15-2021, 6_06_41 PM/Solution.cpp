// https://leetcode.com/problems/network-delay-time

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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        unordered_map<int,vector<vector<int>>>adjList;
        
        for(int i=0;i<times.size();i++)
        {
            adjList[times[i][0]].push_back({times[i][1],times[i][2]});    
        }
        int dist[101];
        int vis[101];
        q.push({0,k});
        for(int i=1;i<=n;i++)
        {
            dist[i]=INT_MAX;
            vis[i]=0;
        }
        dist[k]=0;
        while(!q.empty())
        {
            int index=q.top().second;
            q.pop();
            if(vis[index]==1)continue;
            vis[index]=1;
            vector<vector<int>>candids=adjList[index];
            for(int i=0;i<candids.size();i++)
            {
                int newIndex=candids[i][0],newDist=candids[i][1];
                if(dist[newIndex] > dist[index] + newDist)
                {
                    dist[newIndex]=dist[index] + newDist;
                    q.push({dist[newIndex],newIndex});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
            return -1;
            else
            maxi=max(maxi,dist[i]);
        }
        return maxi;
        
    }
};