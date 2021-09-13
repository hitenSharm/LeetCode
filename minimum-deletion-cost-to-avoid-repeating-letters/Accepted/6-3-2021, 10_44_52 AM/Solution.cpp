// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters


class Solution {
public:
    int minCost(string s, vector<int>& cost) {
       int i=0;int j=0;
       int ans=0;
       while(i<s.length())
       {
          int maxi=0;
          while(j<s.length() && s[i]==s[j])
          {
            ans=ans+cost[j];
            maxi=max(maxi,cost[j]);
            j++;          
          }
          ans=ans-maxi;
          i=j; 
       } 
       return ans;
    }
};