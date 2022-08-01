class Solution {
public:
    vector<vector<int>>dp;
    int recu(vector<int>& nums1,vector<int>& nums2,int i,int j)
    {
        if(i>=nums1.size() || j>=nums2.size())return 0;
        
        if(nums1[i]==nums2[j])
            return dp[i][j]=1+recu(nums1,nums2,i+1,j+1);
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int ans=recu(nums1,nums2,i+1,j);
        ans=max(ans,recu(nums1,nums2,i,j+1));        
        return dp[i][j]=ans;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size(),vector<int>(nums2.size(),-1));
        return recu(nums1,nums2,0,0);
    }
};