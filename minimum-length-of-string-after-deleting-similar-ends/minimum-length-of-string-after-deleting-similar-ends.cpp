class Solution {
public:
    int minimumLength(string s) {
        int i=0,j=s.length()-1;
        while(i<j and s[i]==s[j])
        {
            char tmp=s[i];
            while(i<s.length() and i<j and s[i]==s[j])i++;
            while(j>=0 and s[j]==tmp)j--;
        }
        if(i>j)return 0;
        return j-i+1;
    }
};