#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:  

    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int ans=0;
        vector<vector<int>>grid(n, vector<int> (n, 1));        
        vector<vector<int>>dp(n, vector<int> (n, INT_MAX));                
        for(int i=0;i<mines.size();++i)
        {
            grid[mines[i][0]][mines[i][1]]=0;
        }
        for(int i=0;i<n;++i)
        {
            int l=0;//left to right stores contiguous 1
            for(int j=0;j<n;++j)
            {                
                if(grid[i][j]==1)
                {
                    l++;
                    dp[i][j]=min(dp[i][j],l);
                }
                else
                l=0;
            }
        }
        for(int i=0;i<n;++i)
        {
            int r=0;//right to left stores contiguous 1
            for(int j=n-1;j>=0;--j)
            {                
                if(grid[i][j]==1)
                {
                    r++;
                    dp[i][j]=min(dp[i][j],r);
                }
                else
                r=0;
            }
        }
        for(int i=0;i<n;++i)
        {
            int u=0;//up to down stores contiguous 1
            for(int j=0;j<n;++j)
            {                
                if(grid[j][i]==1)
                {
                    u++;
                    dp[j][i]=min(dp[j][i],u);
                }
                else
                u=0;
            }
        }
        for(int i=0;i<n;++i)
        {
            int d=0;//down to up stores contiguous 1
            for(int j=n-1;j>=0;--j)
            {                
                if(grid[j][i]==1)
                {
                    d++;
                    dp[j][i]=min(dp[j][i],d);
                    ans=max(ans,dp[j][i]);
                }
                else
                d=0;
            }
        }        
        return ans;
    }
};