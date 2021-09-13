// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

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
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0, minEnd = INT_MAX;
        sort(points.begin(),points.end());        
        for(auto& p:points)
        {
          if(minEnd<p[0])
          {            
            minEnd=p[1];
            fl=1;
          }
          else
          {
            minEnd=min(minEnd,p[1]);
            fl=0;
          }
        }        
        return count+1;
    }
};