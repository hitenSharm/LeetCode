// https://leetcode.com/problems/minimum-swaps-to-make-strings-equal

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1.length()!=s2.length())
        return -1;
        int x=0,y=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]=='x')
            x++;
            if(s2[i]=='y')
            y++;
            if(s1[i]=='y')
            y++;
            if(s2[i]=='x')
            x++;
        }
        if(x%2!=0||y%2!=0)
        return -1;
        int xh=0,yh=0;
        int reqx=x/2;
        int reqy=y/2;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]=='x')
            xh++;
            else
            yh++;
        }
        int swaps=max(abs(xh-reqx),abs(yh-reqy));
        int minus=2*swaps;
        for(int i=0;i<s1.length()-1;i++)
        {
            if(s1[i]!=s2[i])
            swaps=swaps+2;
        }
        swaps=swaps-minus;
        return swaps;
    }
};