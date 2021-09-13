// https://leetcode.com/problems/isomorphic-strings

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
    bool isIsomorphic(string s, string t) {
        int freq1[26]={0};
        int freq2[26]={0};
        
        if(s.length()!=t.length())return false;
        
        for(int i=0;i<s.length();i++)
        {
            freq1[s[i]-'a']++;
            freq2[t[i]-'a']++;
            if(freq2[t[i]-'a']!=freq1[s[i]-'a'])
            return false;
        }
        return true;
    }
};