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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=nums[nums.size()-1];
        for(int i=0;i<nums.size();i++)
        {
          if(k>0 && nums[i]<0)
          {
            k--;
            nums[i]=-nums[i];            
          }
          mini=min(mini,nums[i]);
        }
        if(k%2==0 || k==0)
        {
          return accumulate(nums.begin(),nums.end(),0);
        }
        else
        {
          int ans=accumulate(nums.begin(),nums.end(),0);
          ans=ans-(mini*2);
          return ans;
        }
    }
};

