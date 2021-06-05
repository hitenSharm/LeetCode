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
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);horizontalCuts.push_back(0);
        verticalCuts.push_back(w);verticalCuts.push_back(0);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int l=horizontalCuts[0];int b=verticalCuts[0];
        
        for(int i=1;i<horizontalCuts.size();i++)
          l=max(l,horizontalCuts[i]-horizontalCuts[i-1]);
        for(int i=1;i<verticalCuts.size();i++)
          b=max(b,verticalCuts[i]-verticalCuts[i-1]);
        long long mod=1000000007;
        int ans=((l%mod) * (b%mod))%mod;
        return ans;
    }
};