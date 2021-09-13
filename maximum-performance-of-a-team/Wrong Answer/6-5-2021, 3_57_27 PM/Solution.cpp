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
        int ele=0;long long sumHere=0;long long ans=0;
        priority_queue <int, vector<int>, greater<int> > pq;

        for(int i=0;i<vec.size();)
        {
          int eff;
          while(ele<k and i<vec.size())
          {
            eff=vec[i].first;
            sumHere=(sumHere%mod+vec[i].second%mod)%mod;
            pq.push(vec[i].second);
            long long temp=(eff%mod * sumHere%mod)%mod;
            ans=max(ans,temp);
            i++;ele++;
          }          
          sumHere=sumHere-pq.top();
          ele--;
          pq.pop();
        }
        return ans;
    }
};