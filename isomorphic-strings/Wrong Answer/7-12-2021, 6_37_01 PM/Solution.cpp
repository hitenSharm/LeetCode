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
        }
        unordered_map<int,int>ump1;
        unordered_map<int,int>ump2;
        for(int i=0;i<26;i++)
        {
            if(freq2[i]>0)
            ump2[freq2[i]]++;
            if(freq1[i]>0)
            ump1[freq1[i]]++;
        }
        if(ump1.size()!=ump2.size())return false;
        for(auto it:ump1)
        {
            if(ump2.find(it.first)==ump2.end() || it.second!=ump2[it.first])
            return false;
        }
        return true;
    }
};