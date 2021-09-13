// https://leetcode.com/problems/maximum-product-subarray

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevMax=nums[0],prevMin=nums[0];
        int ans=prevMax;
        for(int i=1;i<nums.size();i++)
        {
            int temp=prevMax;
            prevMax=max(prevMax*nums[i],max(prevMin*nums[i],nums[i]));            
            prevMin=min(temp*nums[i],min(prevMin*nums[i],nums[i]));            
            ans=max({prevMin,prevMax,ans});
        }
        return ans;
    }
};