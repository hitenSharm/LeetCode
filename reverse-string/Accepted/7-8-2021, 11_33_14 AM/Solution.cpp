// https://leetcode.com/problems/reverse-string

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
    void reverseString(vector<char>& s) {
      int i=0,j=s.size()-1;
      while(i<=j)
      {
          swap(s[i],s[j]);
          i++;
          j--;
      }
    }
};