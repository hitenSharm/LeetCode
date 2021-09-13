// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>& matrix)
    {        
        if(r+1<matrix.size())
        {
            int ans=INT_MAX;
            ans=min(ans,matrix[r][c]+dfs(r+1,c,matrix));
            if(c-1>=0)
            ans=min(ans,matrix[r][c]+dfs(r+1,c-1,matrix));
            if(c+1<matrix.size())
            ans=min(ans,matrix[r][c]+dfs(r+1,c+1,matrix));
            return ans;
        }
         return matrix[r][c];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            ans=min(ans,dfs(0,i,matrix));
        }
        return ans;
    }
};