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
        unordered_map<int, int>ump;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            while(ump.find(nums[i])!=ump.end())
            {
                cnt++;
                nums[i]++;
            }
            ump[nums[i]]=1;
        }
        return cnt;
    }
};