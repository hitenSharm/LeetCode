// https://leetcode.com/problems/jump-game-vi

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

    int maxResult(vector<int>& nums, int k) {
      deque<int>dq;
      int n=nums.size();
      dq.push_back(n-1);
      for(int i=n-2;i>=0;i--)
      {
        if(dq.front()-k>i)dq.pop_front();
        nums[i]=nums[dq.front()]+nums[i];
        while(dq.size() and nums[dq.back()] < nums[i])
          dq.pop_back();
        dq.push_back(i);
      }
      return nums[dq.front()];
    }
};