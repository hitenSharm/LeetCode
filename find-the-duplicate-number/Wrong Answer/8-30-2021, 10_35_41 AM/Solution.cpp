// https://leetcode.com/problems/find-the-duplicate-number

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size()-1;
        int sum=n*(n+1)/2;
        return accumulate(nums.begin(),nums.end(),0)-sum;
    }
};