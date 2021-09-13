// https://leetcode.com/problems/split-a-string-in-balanced-strings

class Solution {
public:
    int balancedStringSplit(string s) {
        int counter=0;
        int curr=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R')
                curr--;
            if(s[i]=='L')
                curr++;
            if(curr==0)
                counter++;
        }
        return counter;
    }
};