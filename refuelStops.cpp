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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int maxFuel=startFuel;
        int ans=0;int i=0;int dist=0;
        while(dist+maxFuel<target)
        {          
          while(i<stations.size() and maxFuel+dist>=stations[i][0])
          {
            pq.push(stations[i][1]);
            i++;
          }
          if(pq.empty())return -1;
          dist=dist+maxFuel;
          maxFuel=pq.top();
          pq.pop();
          ans++;
        }
        return ans;
    }
};