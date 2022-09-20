class Solution {
public:
    int dp[1001][1001];
//     int lcs(string& s1,string& s2,int i,int j)
//     {
//         if(i<=0 || j<=0)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(s1[i-1]==s2[j-1])return dp[i][j]=1+lcs(s1,s2,i-1,j-1);
        
//         return dp[i][j]=max(lcs(s1,s2,i,j-1),lcs(s1,s2,i-1,j));
//     }
    
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,0,sizeof(dp));                
        
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
        
    }
};