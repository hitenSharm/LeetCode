// https://leetcode.com/problems/remove-covered-intervals

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
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end()) ;
       int left=intervals[0][0];int right=intervals[0][1];
       int ans=1;
       for(int i=1;i<intervals.size();i++)
       {
          if(intervals[i][0]>left and intervals[i][1]>right)
          {
            ans++;
            left=intervals[i][0];
          }
          right=max(right,intervals[i][1]);
       }
       return ans;
    }
};