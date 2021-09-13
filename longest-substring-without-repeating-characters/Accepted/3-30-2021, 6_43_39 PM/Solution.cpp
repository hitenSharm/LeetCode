// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]={0};       
        int j=0;
        int n=s.length();
        int len=1;
        for(int i=0;i<n;i++)
        {            
            while(j<n && freq[s[j]]==0)
            {
                freq[s[j]]++;
                j++;                
            }
            len=max(j-i+1,len);
            freq[s[i]]--;
        }
        return len-1;
    }
};