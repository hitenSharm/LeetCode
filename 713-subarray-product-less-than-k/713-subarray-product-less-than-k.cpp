#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:            
    
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        if(k==0)return ans;
        int prod=1;
        int l=0;
        for(int i=0;i<nums.size();i++)
        {
            prod*=nums[i];
            while(l<=i and prod>=k)
            {
                prod=prod/nums[l];
                l++;
            }
            ans+=(i-l+1);  //as at each new element, n-1 subarrays by adding the new element and 1 for the lonely new elemnet
        }
        return ans;
    }
};