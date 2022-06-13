class Solution {
public:
    int dp[201][201];
    int recu(vector<vector<int>>& triangle,int y,int i)
    {
        if(y==triangle.size() || i>=triangle[y].size())return 0;
        if(dp[y][i]!=-1)return dp[y][i];
        int t1=triangle[y][i]+recu(triangle,y+1,i);
        int t2=triangle[y][i]+recu(triangle,y+1,i+1);
        return dp[y][i]=min(t1,t2);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        return recu(triangle,0,0);
    }
};