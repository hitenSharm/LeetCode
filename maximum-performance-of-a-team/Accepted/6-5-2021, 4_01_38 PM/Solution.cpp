// https://leetcode.com/problems/maximum-performance-of-a-team

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
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>>vec;
        long long mod=1000000007;
        for(int i=0;i<n;i++)
        {
          vec.push_back(make_pair(efficiency[i],speed[i]));
        }
        sort(vec.rbegin(),vec.rend());        
        priority_queue <int, vector<int>, greater<int> > pq;

        long long sumSpeeds=0, ans=0;

        for(auto [eff,speed]:vec)
        {
          pq.push(speed);
          sumSpeeds+=speed;
          if(pq.size()>k)
          {
            sumSpeeds-=pq.top();
            pq.pop();
          }
          ans=max(ans,sumSpeeds*eff);
        }
        
        return ans%mod;
    }
};