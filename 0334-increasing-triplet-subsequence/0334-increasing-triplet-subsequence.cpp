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
        int a=INT_MAX;
        int b=INT_MAX;
        for(auto i:nums)
        {
            if(i<=a){
                a=i;
            }else if(i<=b)
            {
                b=i;
            }
            else
                return true;
        }
        return false;
    }
};