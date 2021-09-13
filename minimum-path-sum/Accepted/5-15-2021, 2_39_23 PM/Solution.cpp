// https://leetcode.com/problems/minimum-path-sum

#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        vector<int>cols(grid[0].size()+1,0);
        vector<vector<int>>dp(grid.size()+1,cols);
        
        dp[0][0]=grid[0][0];
        
        for(int i=1;i<grid[0].size();i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int j=1;j<grid.size();j++)
        {
            dp[j][0]=dp[j-1][0]+grid[j][0];
        }
        
        for(int i=1;i<grid.size();i++)
        {
            for(int j=1;j<grid[0].size();j++)
            {
                dp[i][j]=min(grid[i][j]+dp[i-1][j],grid[i][j]+dp[i][j-1]);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};