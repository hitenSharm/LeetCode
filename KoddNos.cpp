#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
	int atMostKodd(vector<int>&nums,int k)
	{
		int i=0;int j=0;int n=nums.size();
        int odds=0;
        int arrs=0;
        while(i<n && j<n)
        {
        	if(!((nums[j] | 1) > nums[j]))
        		odds++;
        	while(odds>k)
        	{
        		if(!((nums[i] | 1) > nums[i]))
        			odds--;
        		i++;
        	}
        	arrs=arrs+j-i+1;
            j++;
        }
        return arrs;
	}
    int numberOfSubarrays(vector<int>& nums, int k) {
    	return abs(atMostKodd(nums,k)-atMostKodd(nums,k-1));
    }
};