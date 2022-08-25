class Solution {
public:
    bool canConstruct(string ransom, string magazine) {
        unordered_map<char,int>ump;
        for(auto i:magazine)
        {
            ump[i]++;
        }
        for(auto i:ransom)
        {
            ump[i]--;
            if(ump[i]<0)return false;
        }
        return true;
    }
};