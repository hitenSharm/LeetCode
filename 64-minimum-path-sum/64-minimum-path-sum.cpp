class Solution {
public:
    
    vector<vector<int>>dp;
    
//     bool valid(vector<vector<int>>& grid,int i,int j)
//     {
//         if(i>=grid.size() || j>=grid[0].size())return false;
//         return true;
//     }
    
//     int recu(vector<vector<int>>& grid,int i,int j)
//     {
//         if(i==grid.size()-1 and j==grid[0].size()-1)return grid[i][j];
        
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         int ans=INT_MAX;
//         if(valid(grid,i+1,j))
//             ans=min(ans,grid[i][j]+recu(grid,i+1,j));
//         if(valid(grid,i,j+1))
//             ans=min(ans,grid[i][j]+recu(grid,i,j+1));
        
//         return dp[i][j]=ans;
//     }
    
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size(),vector<int>(grid[0].size(),0));
        int n=grid.size();
        int m=grid[0].size();
        dp[n-1][m-1]=grid[n-1][m-1];
        
        for(int i=n-2;i>=0;i--)
            dp[i][m-1] = grid[i][m-1]+dp[i+1][m-1];
        
        for(int j=m-2;j>=0;j--)
            dp[n-1][j] = grid[n-1][j] + dp[n-1][j+1];
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //         cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }            
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                dp[i][j]=grid[i][j] + min(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        return dp[0][0];
    }
};