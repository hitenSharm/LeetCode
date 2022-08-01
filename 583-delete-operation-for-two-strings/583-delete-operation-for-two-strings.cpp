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
    
//     int recu(string& s1,string& s2,int i,int j)
//     {
//         if(i==0 || j==0)return i+j;
        
//         if(s1[i-1]==s2[j-1])return recu(s1,s2,i-1,j-1);
        
//         return min((1+recu(s1,s2,i-1,j)),(1+recu(s1,s2,i,j-1)));
//     }
    
    int minDistance(string word1, string word2) {      
        int dp[501][501];
        
        for(int i=0;i<=word1.size();i++)dp[i][0]=i;
        for(int j=0;j<=word2.size();j++)dp[0][j]=j;
        
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
                }                
            }
        }
        
        return dp[word1.size()][word2.size()];
                
    }
};