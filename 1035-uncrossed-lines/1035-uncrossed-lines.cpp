class Solution {
public:
    vector<vector<int>>dp;
//     int recu(vector<int>& nums1,vector<int>& nums2,int i,int j)
//     {
//         if(i==0 || j==0)return 0;
        
//         if(nums1[i-1]==nums2[j-1])
//             return dp[i][j]=1+recu(nums1,nums2,i-1,j-1);
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int ans=recu(nums1,nums2,i-1,j);
//         ans=max(ans,recu(nums1,nums2,i,j-1));        
//         return dp[i][j]=ans;
//     }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,0));    
        
        for(int i=1;i<=nums1.size();i++)
        {
            for(int j=1;j<=nums2.size();j++)
            {
                if(nums1[i-1]==nums2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};