// https://leetcode.com/problems/maximal-square

class Solution {
public:

    int fillDpArray(vector<vector<char>>& matrix,vector<vector<int>>& dp,int i,int j)
    {
        if(i>=matrix.size()||j>=matrix[0].size())
        return 0;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if(matrix[i][j]=='1')
        {
            return dp[i][j]=1+min(min(fillDpArray(matrix,dp,i+1,j),fillDpArray(matrix,dp,i,j+1)),fillDpArray(matrix,dp,i+1,j+1));
        }
        if(matrix[i][j]=='0')
        return dp[i][j]=0;

        return 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int>row(matrix[0].size(),-1);
        vector<vector<int>>dp(matrix.size(),row);
        int maxi=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                maxi=max(maxi,fillDpArray(matrix,dp,i,j));
            }
        }        
        return maxi*maxi;        
        
    }
};