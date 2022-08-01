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
        // int dp[501][501];
        
        // for(int i=0;i<=word1.size();i++)dp[i][0]=i; //1 based indexing
        // for(int j=0;j<=word2.size();j++)dp[0][j]=j;
        
        vector<int>prev(word2.size()+1,0);
        for(int j=0;j<=word2.size();j++)prev[j]=j;
        vector<int>curr(word2.size()+1,0);
        
        
        for(int i=1;i<=word1.size();i++)
        {
            curr[0]=i;
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])curr[j]=prev[j-1];
                else
                {
                    curr[j]=1+min(prev[j],curr[j-1]);
                }                
            }
            prev=curr;
        }
        
        return prev[word2.size()];
                
    }
};