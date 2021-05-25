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
    vector < int > partitionLabels(string s) {
      int alpha[26];

      for (int i = 0; i < s.length(); i++) {
        alpha[s[i] - 'a'] = i;
      }

      vector < int > arr;

      int i = 0;
      while (i < s.length()) {
        int cnt = 0;
        int window = alpha[s[i] - 'a'];
        while (i <= window) {
          window = max(window, alpha[s[i] - 'a']);
          i++;
          cnt++;
        }
        arr.push_back(cnt);
      }

      return arr;
    }
};