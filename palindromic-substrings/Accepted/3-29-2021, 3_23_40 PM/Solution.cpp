// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:

    int adder(string s,vector<vector<int>> &dp,int i,int j)
    {
        if(i>=j)
        return 1;
        if(dp[i][j]>=0)
        return dp[i][j];

        return dp[i][j]= s[i]==s[j] ? adder(s,dp,i+1,j-1) :0;
        
    }

    int countSubstrings(string s) {
        vector<int>row(s.length(),-1);
        vector<vector<int>>dp(s.length(),row);
        int cnt=0;
       for(int i=0;i<s.length();i++)
       {
           for(int j=i;j<s.length();j++)
           {
               cnt+=adder(s,dp,i,j);
           }
       }
       return cnt;

    }
};