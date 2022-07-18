class Solution {
public:
    
    int recu(string &s1,string &s2,int i,int j)
    {
        //1 based indexing for easier understanding tabulation
        if(i==0)return j;
        if(j==0)return i;
        
        if(s1[i-1]==s2[j-1])return recu(s1,s2,i-1,j-1);
        //insert in s1, 
        return 1+min(recu(s1,s2,i-1,j),min(recu(s1,s2,i,j-1),recu(s1,s2,i-1,j-1)));
        //horses & ros
        //i-1 and j => horse,rose & hors,ros -insertion
        //i & j-1 => horse,ro & horses,ros -removal
    }
    
    int minDistance(string word1, string word2) {
        //from striver
        //base case by 1 based indexing starting from end of string
        //if i==0 return j
        //=> for loop j==0 -> word2.size() dp[0][j]=j
        //similarly for loop i==0 ->word1.size() dp[i][0]=i
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,(vector<int>(m+1,0)));
        
        for(int i=0;i<=n;i++)dp[i][0]=i;
        //means ki ek mein empty string hai and doosre mein there is some length +>delete the extra        
        for(int j=0;j<=m;j++)dp[0][j]=j;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};