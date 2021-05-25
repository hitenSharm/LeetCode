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
    int trap(vector < int > & height) {
      int n = height.size();
      int ans = 0;
      if (n == 0)
        return 0;
      int htLeft[n];
      int tempMax = height[0];
      htLeft[0] = height[0];
      for (int i = 1; i < n; i++) {
        htLeft[i] = max(tempMax, height[i - 1]);
        tempMax = max(tempMax, height[i - 1]);
      }
      int htRight[n];
      htRight[n - 1] = height[n - 1];
      tempMax = height[n - 1];
      int ht[n];
      ht[0] = height[0];
      ht[n - 1] = height[n - 1];
      for (int i = n - 2; i >= 0; i--) {
        tempMax = max(tempMax, height[i + 1]);
        htRight[i] = tempMax;
        ht[i] = min(htRight[i], htLeft[i]);
      }

      for (int i = 0; i < n; i++) {
        if (ht[i] >= height[i]) {
          ans = ans + (ht[i] - height[i]);
        }
      }

      return ans;
    }
};