// https://leetcode.com/problems/find-the-duplicate-number

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l=1,r=nums.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            int cnt=0;
            for(int i=0;i<nums.size();i++)
            if(nums[i]<=m)cnt++;
            if(cnt>m)
            r=m;
            else
            l=m+1;
        }
        return r;
    }
};