class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans=1;
        int mod=1e9+7;
        //tc: o(nlogn)
        //to check for power of 2 : i & (i-1) == 0
        int len=1;
        for(int i=2;i<=n;i++)
        {
            if((i & (i-1))==0)len++; //the bits to shift increases at each power of 2
            ans=((ans << len) + i)%mod; //left shift by the new bits that will come and add
            //i as the come to the units side
        }
        return ans;
    }
};