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
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            int s=0;            
            for(int j=i;j<nums.size();j++)
            {
                s+=nums[j];
                arr.push_back(s);
            }
        }
        partial_sort(arr.begin(),arr.begin()+right,arr.end());
        int s=0;
        for(int i=left-1;i<right;i++)
            s=(s+arr[i])%1000000007;
        return s;
    }
};