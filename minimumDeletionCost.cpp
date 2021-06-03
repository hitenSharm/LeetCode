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
    int minCost(string s, vector<int>& cost) {
       int i=0;int j=0;
       int ans=0;int maxi=0;
       while(i<s.length())
       {
          while(j<s.length() && s[i]==s[j])
          {
            ans=ans+cost[j];
            maxi=max(maxi,cost[j]);
            j++;          
          }
           
       } 
    }
};