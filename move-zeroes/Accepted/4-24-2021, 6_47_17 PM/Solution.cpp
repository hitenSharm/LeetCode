// https://leetcode.com/problems/move-zeroes

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0,j=1;
       while(j<nums.size() && i<nums.size())
       {
           while(i<nums.size() && nums[i]!=0)
           {
                i++;
           }
           if(nums[j]==0||j<=i)
           j++;
           else
           {    
               if(i<nums.size() && j<nums.size())
               {
                   int temp=nums[i];
                   nums[i]=nums[j];
                   nums[j]=temp;
               }
               j++;
           }
       }
    }
};