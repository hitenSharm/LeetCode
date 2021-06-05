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
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> binarySerchOrder;
        for(int i=0;i<nums1.size();i++)
          binarySerchOrder.insert(nums1[i]);

        for(int i=0;i<nums2.size();i++)
        {
          auto it=binarySerchOrder.upper_bound(nums2[i]);
          if(it==binarySerchOrder.end())it=binarySerchOrder.begin();
          nums1[i]=*it;
          binarySerchOrder.erase(it);
        }
        return nums1;
    }
};