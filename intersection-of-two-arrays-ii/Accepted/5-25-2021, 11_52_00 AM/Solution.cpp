// https://leetcode.com/problems/intersection-of-two-arrays-ii

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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {        
        vector<int> ans;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;int j=0;
        while(i<nums1.size() || j<nums2.size())
        {
        	if(i<nums1.size() && j<nums2.size() && nums1[i]==nums2[j])
        	{
        		ans.push_back(nums1[i]);
        		i++;
        		j++;
        		continue;
        	}
        	if(i<nums1.size() && j<nums2.size() && nums1[i]<nums2[j])
        	{
        		i++;
        		continue;
        	}
        	if(i<nums1.size() && j<nums2.size() && nums1[i]>nums2[j])
        	{
        		j++;
        		continue;
        	}
        	i++;j++;
        }
        return ans;
    }
};