// https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations

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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
      if(6 * nums1.size() < 1 * nums2.size() || 6 * nums2.size() < 1 * nums1.size())
            return -1;
       int cumuFreq[6]={0};
       int diff = accumulate(begin(nums1), end(nums1), 0) - accumulate(begin(nums2), end(nums2), 0);

       if(diff > 0) swap(nums1, nums2);
       
       for(int i=0;i<nums1.size();i++)
       cumuFreq[6-nums1[i]]++;

       for(int i=0;i<nums2.size();i++)
        cumuFreq[nums2[i]-1]++;

      int ans=0;
      

      diff=abs(diff);
            
      
      int index=5;
      while(diff>0 and index>0)
      {
        if(cumuFreq[index]>0)
        {
          int ops=min(cumuFreq[index],(int)ceil(1.0 * diff / index));
          diff=diff-(cumuFreq[index]*index);
          cumuFreq[index]=cumuFreq[index]-ops;   
          ans+=ops;       
        }
        index--;
      }
    return ans;
    }
};