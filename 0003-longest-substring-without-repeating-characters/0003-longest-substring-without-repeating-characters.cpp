class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window
        unordered_set<char>words;
        int i=0,j=0;
        int ans=0;
        while(i<s.size())
        {
            while(j<s.size() and words.find(s[j])==words.end())
            {
                words.insert(s[j]);
                j++;
            }
            ans=max(ans,j-i);
            words.erase(s[i]);
            i++;
        }
        return ans;
    }
};