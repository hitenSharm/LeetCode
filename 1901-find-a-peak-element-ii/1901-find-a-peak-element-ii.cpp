class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int l=0,r=mat[0].size()-1;
		int rm;
		while(l<=r)
		{
			int m=l+(r-l)/2;
			int maxi=0;
			for(int i=0;i<mat.size();i++)
			{
				if(mat[i][m]>maxi)
				{
					maxi=mat[i][m];
					rm=i;
				}
			}
			if(l==r)return {rm,l};
			if(mat[rm][m]>mat[rm][m+1])
			r=m;
			else
			l=m+1;
		}
		return {0,0};
    }
};