// https://leetcode.com/problems/maximum-product-subarray

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int mini=nums[0];
        int maxProd=nums[0];
        int maxi=mini;
        for(int i=0;i<nums.size();i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            prod=prod*nums[i];
            maxProd=max(maxProd,prod);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
              prod=prod/nums[i];
              maxProd=max(maxProd,prod);  
            }
            else
                continue;
        }
        return max(maxi,maxProd);
    }
};