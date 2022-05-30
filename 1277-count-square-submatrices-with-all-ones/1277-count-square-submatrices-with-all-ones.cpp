class Solution {
public:
	int dirs[4]={0,1,1,0};

	int recu(vector<vector<int>>& sq,vector<vector<int>>& matrix,int i,int j)
	{
		if(i==matrix.size() || j==matrix[i].size() || matrix[i][j]==0)return 0;
		if(sq[i][j]!=-1)return sq[i][j];
		int ans=INT_MAX;
		for(int k=0;k<3;k++)
		{
			int ni=dirs[k]+i,nj=j+dirs[k+1];
			ans=min(ans,1+recu(sq,matrix,ni,nj));
		}
		return sq[i][j]=ans;
	}

    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>>sq(matrix.size(), vector<int> (matrix[0].size(),-1));
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[i].size();j++)
			{
				if(matrix[i][j]==1 and sq[i][j]==-1)
				{
					recu(sq,matrix,i,j);
				}
			}
		}
		int ans=0;
		for(int i=0;i<matrix.size();i++)
		{
			for(int j=0;j<matrix[i].size();j++)
			{
				if(sq[i][j]!=-1)
				ans+=sq[i][j];
			}            
		}
		return ans;
    }
};