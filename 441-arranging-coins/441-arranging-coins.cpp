class Solution {
public:
    int arrangeCoins(long long n) {
        long long l=1,r=n;
        long long ans=-1;
        while(l<=r)
        {
        	long long m=l+(r-l)/2;
        	long long cnt=(m*(m+1)/2);        	
        	if(cnt<=n)
        	{
        		ans=m;
        		l=m+1;
        	}
        	else
        		r=m-1;
        }
        return ans;
    }
};