class Solution {
public:
    string breakPalindrome(string s) {
        string s1=s;
        string s2=s;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!='a'){
                s1[i]='a';
                break ;
            }
        }
        string res=s1;
        reverse(res.begin(),res.end());
        if(res!=s1)return s1;
        for(int i=s1.size()-1;i>=0;i--)
        {
            if(s2[i]!='b'){
                s2[i]='b';
                break ;
            }
        }
        res=s2;
        reverse(res.begin(),res.end());
        if(res!=s2)return s2;
        
        return "";
    }
};