// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>freq;
        int i=0,j=0,len=0;
        while(i<s.length())
        {
            while(j<s.length() and freq[s[j]]==0)
            {
                freq[s[j]]++;
                j++;
            }
            len=max(j-i,len);
            freq[s[i]]--;
            i++;
        }
        return len;
    }
};