// https://leetcode.com/problems/move-zeroes

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0,j=1;
       while(j<nums.size())
       {
           while(nums[i]!=0 && i<nums.size())
           i++;
           if(nums[j]==0)
           j++;
           else
           {               
               swap(nums[i],nums[j]);
           }
       }
    }
};