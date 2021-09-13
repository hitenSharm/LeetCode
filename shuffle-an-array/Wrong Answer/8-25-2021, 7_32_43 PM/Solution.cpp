// https://leetcode.com/problems/shuffle-an-array

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
    vector<int>ogArr;
    vector<int>arr;
    Solution(vector<int>& nums) {
        ogArr=nums;
        arr=nums;
        sort(arr.begin(),arr.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return ogArr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */