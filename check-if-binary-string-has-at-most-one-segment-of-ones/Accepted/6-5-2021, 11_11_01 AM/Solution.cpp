// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

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
    bool checkOnesSegment(string s) {
        return (string::npos == s.find("01"));
    }
};