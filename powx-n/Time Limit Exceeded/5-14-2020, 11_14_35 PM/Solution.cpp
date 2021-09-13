// https://leetcode.com/problems/powx-n

class Solution {
public:
    double myPow(double x, int n) {
        if(n>0)
        {
            double ans=1;
            while(n--)
            {
                ans=ans*x;
            }
            return ans;
        }
         if(n<0)
         {
            double ans=-x;
            while(n--)
            {
                ans=ans/x;
            }
            return ans;
             
         }
        if(n==0)
            return 0;
        return 0;
        
    }
};