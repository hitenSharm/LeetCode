class Solution {
public:

    void makeZeros(int i,int j,vector<vector<int>>& matrix)
    {
        for(int ni=0;ni<matrix.size();ni++)
            matrix[ni][j]=0;
        for(int nj=0;nj<matrix[0].size();nj++)
            matrix[i][nj]=0;
    }

    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>>q;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                if(matrix[i][j]==0)q.push({i,j});
            }
        }
        while(!q.empty())
        {
            pair<int,int>& p=q.front();
            int i=p.first,j=p.second;
            makeZeros(i,j,matrix);
            q.pop();
        }        
    }
};