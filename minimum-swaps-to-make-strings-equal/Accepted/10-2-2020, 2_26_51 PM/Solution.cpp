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
        int cnt1=0,cnt2=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]=='x'&&s2[i]=='y')
                cnt1++;
            if(s1[i]=='y'&&s2[i]=='x')
                cnt2++;
        }
        return ((cnt1/2)+(cnt2/2)+(cnt1%2)+(cnt2%2));
       
    }
};