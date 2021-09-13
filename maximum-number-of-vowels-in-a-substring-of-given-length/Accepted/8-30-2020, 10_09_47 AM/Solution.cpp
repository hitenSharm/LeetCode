// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

class Solution {
public:
    int maxVowels(string s, int k) {
        int c=0;
        int vmax=0;
        int j=0;
        int n=s.length();
        
        for(int i=0;i<s.length();i++){ 
            while(k>0&&j<n){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    c++;
                    vmax=max(c,vmax);
                }
                j++;
                k--;
            }
            vmax=max(c,vmax);
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                c--;
            }
            k++;
            
        }
        
       return vmax; 
    }
};