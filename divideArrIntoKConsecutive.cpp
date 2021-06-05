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
    bool isPossibleDivide(vector < int > & nums, int k) {
      map < int, int > mp;
      for (int i = 0; i < nums.size(); i++)
        mp[nums[i]]++;

      while (mp.size() > 0) {
        auto it = mp.begin();
        int temp = k;
        int x = it -> first;
        while (temp > 0) {
          mp[x]--;
          if (mp[x] == 0) mp.erase(x);
          temp--;
          if (mp.find(x + 1) == mp.end())
            break;
          else
            x = x + 1;
        }
        if (temp > 0)
          return false;
      }
      return true;
    }
};