class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int j=0;j<matrix[0].size();j++)
        {
            int tj=j;
            int i=0;
            int temp=matrix[i][j];
            while(tj<matrix[0].size() and i<matrix.size())
            {
                if(temp!=matrix[i][tj])return false;
                i++;
                tj++;
            }
        }
        for(int j=0;j<matrix.size();j++)
        {
            int tj=j;
            int i=0;
            int temp=matrix[j][i];
            while(tj<matrix.size() and i<matrix[0].size())
            {
                if(temp!=matrix[tj][i])return false;
                i++;
                tj++;
            }
        }
        return true;
    }
};