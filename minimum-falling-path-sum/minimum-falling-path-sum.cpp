class Solution {
public:

    int dp[101][101];

    int dfs(int r,int c,vector<vector<int>>& matrix)
    {   
        if(dp[r][c]!=-1)return dp[r][c];
        if(r+1<matrix.size())
        {
            int ans=INT_MAX;
            ans=min(ans,matrix[r][c]+dfs(r+1,c,matrix));
            if(c-1>=0)
            ans=min(ans,matrix[r][c]+dfs(r+1,c-1,matrix));
            if(c+1<matrix.size())
            ans=min(ans,matrix[r][c]+dfs(r+1,c+1,matrix));
            return dp[r][c]=ans;
        }
         return dp[r][c]=matrix[r][c];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++)
        {
            ans=min(ans,dfs(0,i,matrix));
        }
        return ans;
    }
};