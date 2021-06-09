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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>ump(nums.begin(),nums.end());        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
          if(ump.find(nums[i])==ump.end())continue;
          else
          {
            int prev=nums[i]-1;int fwd=nums[i]+1;
            ump.erase(nums[i]);
            int tempAns=1;
            while(ump.find(prev)!=ump.end())
            {
              ump.erase(prev);
              tempAns++;
              prev--;
            }
            while(ump.find(fwd)!=ump.end())
            {
              ump.erase(fwd);
              tempAns++;
              fwd++;
            }
            ans=max(ans,tempAns);
          }
        }
        return ans;
    }
};