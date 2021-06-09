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
    vector<int> mostCompetitive(vector<int>& nums, int k) {
       vector<int>st;
       for(int i=0;i<nums.size();i++)
       {
        //if we have options and the curr elem is less than top of stack , so we can get a better array so pop till better
        while(!st.empty() and nums[i]<st.back() and nums.size()-i+st.size()-1>=k)
          st.pop_back();
        if(st.size()<k)
          st.push_back(nums[i]);
       } 
       return st;
    }
};