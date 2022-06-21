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
    int longestBeautifulSubstring(string word) {
        int i=0,j=0;
        char validate[5]={'a','e','i','o','u'};
        int len=0;
        while(j<word.size())
        {
            if(word[j]=='a')
            {
                i=j;
                int start=0;                
                while((start<5 and word[i]==validate[start]) || (start+1<5 and word[i]==validate[start+1]))
                {
                    if(start+1<5 and word[i]==validate[start+1])start++;
                    i++;
                }                
                if(word[i-1]=='u')len=max(len,i-j);
                j=i;
            }    
            else
                j++;
        }
        return len;
    }
};