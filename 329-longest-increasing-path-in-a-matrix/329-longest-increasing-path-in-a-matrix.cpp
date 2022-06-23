class Solution {
public:
	
	int dirs[5]={-1,0,1,0,-1};
	int dp[201][201];
	int recu(int i,int j,vector<vector<int>>& matrix)
	{
        if(dp[i][j]!=-1)return dp[i][j];
		int temp=matrix[i][j];			
		int ans=0;
		for(int k=0;k<4;++k)
		{
			int ni=i+dirs[k],nj=j+dirs[k+1];
			if(ni>=0 and nj>=0 and ni<matrix.size() and nj<matrix[0].size() and matrix[ni][nj]>temp)
			{
                matrix[i][j]=-1;
				ans=max(ans,1+recu(ni,nj,matrix));
                matrix[i][j]=temp;
			}
		}
		return dp[i][j]=ans;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
		int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[i].size();++j)
			{
				ans=max(ans,1+recu(i,j,matrix));
			}
		}
		return ans;
    }
};