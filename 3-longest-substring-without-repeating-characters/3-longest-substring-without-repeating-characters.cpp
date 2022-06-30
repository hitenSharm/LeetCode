class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        unordered_set<char>ust;
        int len=0;
        while(i<s.size())
        {
            while(j<s.size() and ust.find(s[j])==ust.end())
            {
                ust.insert(s[j]);
                j++;
            }
            len=max(len,j-i);
            ust.erase(s[i]);
            i++;
        }
        return len;
    }
};