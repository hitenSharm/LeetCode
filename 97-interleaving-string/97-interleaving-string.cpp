class Solution {
public:
    vector<vector<int>>dp;
    int recu(string& s1,string& s2,string& s3,int i,int j,int k)
    {
        if(i>=s1.size() and j>=s2.size() and k>=s3.size())return 1;        
        int ans=0;
        if(i<s1.size() and j<s2.size() and dp[i][j]!=-1)return dp[i][j];
        if(i<s1.size() and s1[i]==s3[k])
        {
            ans=max(ans,recu(s1,s2,s3,i+1,j,k+1));
        }
        if(j<s2.size() and s2[j]==s3[k])
        {
            ans=max(ans,recu(s1,s2,s3,i,j+1,k+1));
        }        
        return dp[i][j]=ans;
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return (recu(s1,s2,s3,0,0,0)==1);
    }
};