// https://leetcode.com/problems/move-zeroes

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]==0)
            {
                int t=i;
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[j]==0)break;
                    swap(nums[j],nums[t]);
                    t++;
                }
            }
        }
    }
};