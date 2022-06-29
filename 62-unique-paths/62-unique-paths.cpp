class Solution {
public:
    
    int recu(vector<vector<int>>& dp,int i,int j,int& m,int& n)
    {
        if(i==m-1 and j==n-1)return 1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int t1=0,t2=0;
        if(i+1<m)t1=recu(dp,i+1,j,m,n);
        if(j+1<n)t2=recu(dp,i,j+1,m,n);
        return dp[i][j]=t1+t2;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recu(dp,0,0,m,n);
    }
};