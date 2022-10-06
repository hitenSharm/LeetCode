class Solution {
public:
    
    int getAns(vector<vector<int>>& mat,int i,int j)
    {
        int m=mat.size();
        int bound=mat[0].size();
        //bound is as when moving down we can only extend till minimu of the extedes above
        //see fraz vid
        int ans=0;
        for(int p=i;p<mat.size();p++)
        {
            for(int q=j;q<bound;q++)
            {
                if(mat[p][q]==1)ans++;
                else
                    bound=q;
            }
        }
        return ans;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==1)ans+=getAns(mat,i,j);
            }
        }
        return ans;
    }
};