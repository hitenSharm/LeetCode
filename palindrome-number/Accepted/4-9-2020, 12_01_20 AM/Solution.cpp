// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
    ostringstream str1; 
  
    str1 << x; 
  
  
    string geek = str1.str();
        string s=geek;
       reverse(geek.begin(), geek.end()); 
     if(s==geek)
         return true;
      else
          return false;
        
        
    }
};