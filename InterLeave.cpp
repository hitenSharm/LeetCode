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

    int dp[101][101];

  int recu(string & s1, string & s2, string & s3, int i, int j, int k) {
    if (i > s1.length() || j > s2.length() || k > s3.length())
      return 0;
    if (i == s1.length() && j == s2.length() && k == s3.length())
      return 1;
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    if (s1[i] == s3[k] && s2[j] == s3[k]) {
      return dp[i][j] = max(recu(s1, s2, s3, i + 1, j, k + 1), recu(s1, s2, s3, i, j + 1, k + 1));
    }
    if (s1[i] == s3[k] && s2[j] != s3[k]) {
      return dp[i][j] = recu(s1, s2, s3, i + 1, j, k + 1);
    }
    if (s2[j] == s3[k] && s1[i] != s3[k]) {
      return dp[i][j] = recu(s1, s2, s3, i, j + 1, k + 1);
    } else
      return 0;
    return -1;
  }

  bool isInterleave(string s1, string s2, string s3) {
    memset(dp, -1, sizeof(dp));
    int ans = recu(s1, s2, s3, 0, 0, 0);
    if (ans == 0)
      return false;
    return true;
  }
};