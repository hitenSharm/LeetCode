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
    int waysToSplitArray(vector<int>& nums) {
        long long s=accumulate(nums.begin(),nums.end(),0LL);
        long long ans=0;
        long long sHere=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sHere+=nums[i];
            s-=nums[i];
            if(sHere>=s)
                ans++;            
        }
        return ans;
    }
};