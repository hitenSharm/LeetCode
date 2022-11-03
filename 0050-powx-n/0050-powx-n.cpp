class Solution {
public:
    
    double fastCalc(double x,int n)
    {
        if(n==0)return 1.0;
        
        double half=fastCalc(x,n/2);
        if(n%2==0)
            return half*half;
        else
            return half*half*x;
    }
    
    double myPow(double x, int n) {
        if(n<0)
        {
            x=1/x;
            n=abs(n);
        }
        return fastCalc(x,n);
    }
};