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
    bool chk(string s,string t)
    {
        unordered_map<char,char>ump;
        if(s.length()!=t.length())return false;
        
        for(int i=0;i<s.length();i++)
        {
            if(ump.find(s[i])==ump.end())
            {
                ump[s[i]]=t[i];
                s[i]=t[i];                
            }
            else
            {
                s[i]=ump[s[i]];
            }
        }        
        if(s==t)
        return true;
        
        return false;
    }
    bool isIsomorphic(string s, string t) {
        if(chk(s,t) and chk(t,s))return true;
        return false;
    }
};