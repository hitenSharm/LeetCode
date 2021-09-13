// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

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
    int minimumDeletions(string s) {
        int index=0;int fl=0;
        int bCnt=0, aCnt=0;
        int ans=0;
        for(;index<s.length();)
        {
          if(s[index]=='a' and fl==0)
            index++;
          else
          {
            fl=1;
            while(s[index]=='b' and index<s.length())
            {
              bCnt++;index++;
            }
            while(s[index]=='a' and index<s.length())
            {
              aCnt++;index++;
            }
            if(bCnt==aCnt)
            {
              ans+=bCnt;
              bCnt=0;
              aCnt=0;
            }
            else if(bCnt>aCnt and aCnt!=0)
            {
              ans+=aCnt;
              aCnt=0;
            }
            else if(aCnt>bCnt)
            {
              ans+=bCnt;
              bCnt=0;aCnt=0;
            }
          }
        }
        return ans;
    }
};