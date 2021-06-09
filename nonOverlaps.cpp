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
    int eraseOverlapIntervals(vector < vector < int >> & intervals) {
      int cnt = 0;
      int ans = 0;
      int minVal = INT_MAX;
      sort(intervals.begin(), intervals.end());

      for (auto & i: intervals) {
        if (i[0] >= minVal) {
          ans = ans + cnt - 1;
          cnt = 1;
          minVal = i[1];
        } else {
          cnt++;
          minVal = min(minVal, i[1]);
        }
      }
      if (cnt != 0)
        ans = ans + cnt - 1;
      return ans;

    }
};