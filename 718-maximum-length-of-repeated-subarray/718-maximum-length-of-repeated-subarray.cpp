#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

// int ans=0;
//     int dp[1001][1001];
//     int recu(vector<int>& n1,vector<int>& n2,int i,int j)
//     {
//         if(i>=n1.size() || j>=n2.size())return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int temp=max(recu(n1,n2,i+1,j),recu(n1,n2,i,j+1));//first we explore wether we include or exclude the index
//         int t2;
//         if(n1[i]==n2[j])
//         {
//             t2=recu(n1,n2,i+1,j+1);
//             temp=max(temp,1+t2);            
//         }
//         ans=max(ans,temp);
//         if(n1[i]==n2[j])return dp[i][j]=1+t2; //if element is equal we can do 1+recu()
//         return dp[i][j]=0;//when elements are not equal we have to skip elements and return a 0
//     }
    
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         memset(dp,-1,sizeof(dp));
//         recu(nums1,nums2,0,0);
//         return ans;
//     }


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1001][1001];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=1;i<=nums1.size();i++)
        {
            for(int j=1;j<=nums2.size();j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};