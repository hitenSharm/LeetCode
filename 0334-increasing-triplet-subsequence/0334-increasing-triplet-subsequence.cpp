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
    bool increasingTriplet(vector<int>& nums) {
        vector<int>prefix(nums.size());
        vector<int>suff(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            prefix[i]=min(prefix[i-1],nums[i]);
        suff[nums.size()-1]=nums.back();
        for(int i=nums.size()-2;i>=0;i--)
        {
            suff[i]=max(suff[i+1],nums[i]);            
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>prefix[i-1] and nums[i]<suff[i+1])return true;
        }
        return false;
    }
};