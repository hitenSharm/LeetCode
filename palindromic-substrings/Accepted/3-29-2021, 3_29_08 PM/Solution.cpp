// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int count;
    int countSubstrings(string s) 
    {
        count=0;
        int n=s.length();
        //If string is of length 0 or 1 then it is a palindrome of length 1
        if(n<2)
            return 1;
        //We will expand around centers from i=0 to i=n-1 
        for(int i=0;i<n;i++)
        {
            //For odd length strings middle character will be a palindrome
            //We need to expand from that middle character towards left and right
            expand(s,i,i);
            //For even length strings there will be two middle characters
            //We need to expand from first char to left and from second char to right
            expand(s,i,i+1);
        }
        
        return count;
    }
     void expand(string s,int i,int j)
    {
        //Simple algorithm to check the expanse of Palindrome
        while(i>=0 && j<s.length() && s[i]==s[j])
        {
            i--;
            j++;
            count++;
        }
   
        return;
    }
    
};