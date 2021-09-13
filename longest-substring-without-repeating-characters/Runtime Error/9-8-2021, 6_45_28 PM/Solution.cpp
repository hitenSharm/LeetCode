// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[26]={0};
        int i=0,j=0,len=0;
        while(i<s.length())
        {
            while(j<s.length() and freq[s[j]-'a']==0)
            {
                freq[s[j]-'a']++;
                j++;
            }
            len=max(j-i,len);
            freq[s[i]-'a']--;
            i++;
        }
        return len;
    }
};