// https://leetcode.com/problems/first-bad-version

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=0;int r=n;
        int bad=INT_MAX;
        while(l<=r)
        {
          int m=l+(r-l)/2;
          if(isBadVersion(m))
          {
            bad=min(bad,m);
            r=m-1;
          }
          else
            l=m+1;
        }
        return bad;
    }
};