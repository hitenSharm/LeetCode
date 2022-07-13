class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>ump;
        for(auto i:s)ump[i]++;
        unordered_map<char,int>ump2;
        for(int i=0;i<t.size();i++)
        {
            if(ump.find(t[i])==ump.end())return false;
            ump2[t[i]]++;
        }
        for(auto it:ump)
        {
            if(ump2[it.first]!=it.second)return false;
        }
        return true;
    }
};