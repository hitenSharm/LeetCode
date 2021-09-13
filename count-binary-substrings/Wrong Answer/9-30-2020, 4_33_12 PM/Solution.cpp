// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr=0;
        int ans=0;
        int prev=0;
        if(s[0]=='0')
                curr++;
        else
                curr--;
        for(int i=1;i<s.length();i++)
        { 
            prev=curr;
            if(s[i]=='0')
                curr++;
            else
                curr--;
            if(prev<=0&&curr>prev)
                ans++;
            if(prev>=0&&curr<prev)
                ans++;
        }
        return ans;
    }
};