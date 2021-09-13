// https://leetcode.com/problems/subarray-product-less-than-k

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long i=0;long j=0;
        long n=nums.size();
        long prod=1;
        long ans=0;
        long pj=0;
        long fl=0;        
        while(i<n && j<n)
        {        	
        	while(j<n && (prod*nums[j])<k)
        	{
        		prod=prod*nums[j];                
        		j++;         		
        	}
        	long len=j-i;            
        	long temp1=len*(len+1)/2;
        	if(fl==0)
        	{                                
        		fl=1;
        		ans+=temp1;
        	}
        	else
        	{
        		long len2=pj-i+1;
        		long temp2=len2*(len2+1)/2;
        		ans=ans+(temp1-temp2);
        	}
        	prod=prod/nums[i];
        	i++;
        	if(i>j)
            {
                fl=0;
                j=i;
                prod=1;
            }            
            pj=j-1;    
            
        }
        return ans;
    }
};