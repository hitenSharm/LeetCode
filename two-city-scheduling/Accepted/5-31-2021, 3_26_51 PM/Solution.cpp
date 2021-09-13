// https://leetcode.com/problems/two-city-scheduling

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
    int twoCitySchedCost(vector<vector<int>>& costs) {
       sort(costs.begin(),costs.end(), [](vector<int> &v1, vector<int> &v2){
          return (v1[0] - v1[1] < v2[0] - v2[1]);
       });
       int ans=0;
       for(int i=0;i<costs.size();i++)
       {
        if(i<costs.size()/2)
          ans+=costs[i][0];
        else
          ans+=costs[i][1];
       }
       return ans;
    }
};