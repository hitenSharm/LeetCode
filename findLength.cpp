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
    
    vector<vector<int>>dp;
    int ans=0;
    int recu(vector<int>& nums1,vector<int>& nums2,int i,int j)
    {
        if(i>=nums1.size() || j>=nums2.size())
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        recu(nums1,nums2,i+1,j);recu(nums1,nums2,i,j+1);
        
        if(nums1[i]==nums2[j])
        dp[i][j]=1+recu(nums1,nums2,i+1,j+1);
        
        if(nums1[i]!=nums2[j])
        dp[i][j]=0;
        
        ans=max(ans,dp[i][j]);
        return dp[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(size(nums1), vector<int>(size(nums2), -1));
        recu(nums1,nums2,0,0);
        return ans;
    }
};