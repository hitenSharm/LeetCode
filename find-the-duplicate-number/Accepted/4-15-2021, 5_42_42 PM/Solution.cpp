// https://leetcode.com/problems/find-the-duplicate-number

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1;
        int high=nums.size();
        int mid=0, count=0;
        
        while(low<high){
            mid=(low+high)/2;
            count=0;
            for(auto num : nums)
                if(num<=mid)  count++;
            if(count<=mid)
                low=mid+1;
            else 
                high=mid;
        }
        return low;
    }
};