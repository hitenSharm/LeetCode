// https://leetcode.com/problems/move-zeroes

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>arr;
        int curr=0;
        
        for(int i=0;i<nums.size();i++)
         if(nums[i]==0)
            arr.push_back(i);
        
        for(int i=0;i<nums.size();i++)
        {
           if(arr.size()>0 && nums[i]!=0)
            {
                swap(nums[i],nums[arr[curr]]);
                if(curr+1<arr.size())
                {
                    if(arr[curr+1]>i)
                    arr[curr]=i;
                    else
                    curr++;
                }
            }
        }
    }
};