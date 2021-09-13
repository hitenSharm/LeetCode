// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=1;
        int kount=1;
        int x=s.length();
        for(int i=0;i<x;++i)
        {
            if(i+1<x)
            {
             if(s[i]!=s[i+1]&&count(s.begin(),s.begin()+i+1,s[i+1])<1){
              kount++;
               if(kount>=maxi)
               {
                    maxi=kount;
               }
             }
                if(s[i]==s[i+1])
                    kount=1;
            }
        }
        if(x==0)
            return 1;
        if(x==1)
        return 1;
       return maxi; 
    }
};