// https://leetcode.com/problems/ways-to-make-a-fair-array

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
    int waysToMakeFair(vector<int>& nums) {
        vector<int>even;
        vector<int>odd;
        int ev=0;int od=0;
        even.push_back(ev);odd.push_back(od);
        for(int i=0;i<nums.size();i++)
        {
          if((i | 1)>i)
            ev+=nums[i];
          else
            od+=nums[i];
          even.push_back(ev);odd.push_back(od);
        }
        int cnt=0;int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
          int odCnt=even[n]-even[i+1]+odd[i];
          int evCnt=odd[n]-odd[i+1]+even[i];
          if(odCnt==evCnt)
            cnt++;
        }
        return cnt;
    }
};