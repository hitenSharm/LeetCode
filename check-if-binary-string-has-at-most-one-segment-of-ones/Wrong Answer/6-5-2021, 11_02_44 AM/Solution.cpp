// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        int fl=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='1' and s[i+1]=='1' and fl==0)
                fl=1;
            else if(s[i]=='1' and s[i+1]=='1' and fl==1)
                return false;
        }
        if(fl==1)
        return true;
        
        return false;
    }
};