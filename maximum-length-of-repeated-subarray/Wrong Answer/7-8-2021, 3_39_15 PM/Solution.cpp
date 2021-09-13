// https://leetcode.com/problems/maximum-length-of-repeated-subarray

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
    
    int dp[1001][1001];
    
    int recu(vector<int>& nums1,vector<int>& nums2,int i,int j)
    {
        if(i>=nums1.size() || j>=nums2.size())
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        int ans=INT_MIN;
        
        if(nums1[i]==nums2[j])
        ans=1+recu(nums1,nums2,i+1,j+1);
        
        ans=max(ans,max(recu(nums1,nums2,i+1,j),recu(nums1,nums2,i,j+1)));
        
        return dp[i][j]=ans;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int ans=recu(nums1,nums2,0,0);
        return ans;
    }
};