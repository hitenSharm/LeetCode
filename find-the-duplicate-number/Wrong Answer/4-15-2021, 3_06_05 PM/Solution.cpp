// https://leetcode.com/problems/find-the-duplicate-number

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int maxi=*max_element(a.begin(), a.end());
        return (accumulate(a.begin(), a.end(), 0) - (maxi*(maxi+1)/2));
    }
};