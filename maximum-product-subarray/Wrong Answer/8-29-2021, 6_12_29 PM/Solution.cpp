// https://leetcode.com/problems/maximum-product-subarray

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=1;
        int prodnegs=1;
        vector<int>posi(nums.size());
        vector<int>negi(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                prod=prod*nums[i];
                prodnegs=prodnegs*nums[i];
                posi[i]=prod;negi[i]=prodnegs;
            }
            if(nums[i]<0)
            {
                prodnegs=prodnegs*nums[i];
                negi[i]=prodnegs;
                posi[i]=0;
                prod=1;
            }
            if(nums[i]==0)
            {
                prod=1;
                posi[i]=0;
                prodnegs=1;
                negi[i]=0;
            }
        }
        int ans=*max_element(posi.begin(),posi.end());
        ans=max(ans,*max_element(negi.begin(),negi.end()));
        return ans;
    }
};