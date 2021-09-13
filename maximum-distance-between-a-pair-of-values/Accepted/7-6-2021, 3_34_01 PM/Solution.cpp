// https://leetcode.com/problems/maximum-distance-between-a-pair-of-values

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

    int binarySearch(int& nums1,int& i,vector<int>& nums2)
    {
        int l=i;
        int r=nums2.size()-1;
        int ans=0;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(nums2[m]>=nums1)
            {
               ans=max(ans,m-i);
               l=m+1;
            }
            else
            r=m-1;
        }
        return ans;
    }

    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            ans=max(ans,binarySearch(nums1[i],i,nums2));
        }
        return ans;
    }
};