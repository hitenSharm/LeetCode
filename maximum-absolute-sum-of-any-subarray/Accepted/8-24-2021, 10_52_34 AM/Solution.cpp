// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray

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
    int maxAbsoluteSum(vector<int>& nums) {
        int neg=0;
        int pos=0;
        int stillhere=0;
        int stillhere2=0;
        for(int i=0;i<nums.size();i++)
        {
            stillhere+=nums[i];
            stillhere2+=nums[i];
            neg=min(neg,stillhere2);
            pos=max(pos,stillhere);
            if(stillhere<0)stillhere=0;
            if(stillhere2>0)stillhere2=0;
        }
        return max(abs(neg),pos);
    }
};