class Solution {
public:
    int dp[501][501];
    int recu(string& s1,string& s2,int i,int j)
    {
        if(i==s1.size() || j==s2.size())return ((s1.size()-i)+(s2.size()-j));
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return recu(s1,s2,i+1,j+1);
        
        return dp[i][j]=min((1+recu(s1,s2,i+1,j)),(1+recu(s1,s2,i,j+1)));
    }
    
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return recu(word1,word2,0,0);
    }
};