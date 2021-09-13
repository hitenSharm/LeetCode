// https://leetcode.com/problems/minimum-increment-to-make-array-unique

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int maxi=INT_MIN;
        int i=0,j=0;
        while(i<nums.size())
        {
            while(j<nums.size() and nums[i]==nums[j])
                j++;
            if(nums[i]>maxi)
            {
                int len=j-i-1;
                cnt=cnt+(len*(len+1)/2);
                maxi=nums[i]+len;
                i=j;
            }
            else
            {
                int len=j-i;
                int inc=maxi-nums[i];
                cnt=cnt+(inc*len)+(len*(len+1)/2);
                maxi=maxi+len;
                i=j;
            }
        }
        return cnt;
    }
};