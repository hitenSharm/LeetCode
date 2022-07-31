class Solution {
public:
    int arrangeCoins(int n) {
        // long ans=0;
        // int l=1,r=n;
        // while(l<=r)
        // {
        //     long m=l+(r-l)/2;
        //     long coins=(m*(m+1)>>1);            
        //     if(coins>n)
        //         r=m-1;
        //     else
        //     {
        //         ans=m;
        //         l=m+1;
        //     }
        // }
        // return ans;
        return (int)floor(sqrt(2 * double(n + 0.25)) - 0.5);        
    }
};