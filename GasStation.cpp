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
    int canCompleteCircuit(vector < int > & gas, vector < int > & cost) {

      if (accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0) < 0)
        return -1;

      int diff = 0;
      int i = 0;
      int len = 0;
      int start = 0;
      while (start < gas.size()) {
        if (len == gas.size())
          return start;
        diff = diff + gas[i] - cost[i];
        if (start == gas.size() - 1 and diff < 0)
          break;
        if (diff < 0) {
          diff = 0;
          len = 0;
          start = i + 1;
        } else
          len++;
        i = (i + 1) % gas.size();
      }

      return -1;
    }
};