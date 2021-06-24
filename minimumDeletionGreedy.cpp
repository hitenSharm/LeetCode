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
        int bCnt=0,deletions=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='b')
            bCnt++;
            else
            {
                if(bCnt>0)
                {
                    bCnt--;
                    deletions++;
                    continue;
                }
            }
        }
        return deletions;
    }
};