class Solution {
public:

    vector<vector<int>>dp;

    int recu(string& s,string& s2,int i,int j)
    {
        if(i>=s.size() || j>=s2.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s[i]==s2[j])return dp[i][j]=(1+recu(s,s2,i+1,j+1));
        
        return dp[i][j]=max(recu(s,s2,i+1,j),recu(s,s2,i,j+1));
    }


    int lcs(string& s,string& s2)
    {
        return recu(s,s2,0,0);
    }

    int longestPalindromeSubseq(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        string s2=s;
        reverse(s2.begin(),s2.end());
        return lcs(s,s2);
    }
};