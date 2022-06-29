class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int divi=matrix[0].size();
        int l=0,r=(matrix.size()*divi)-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int i=m/divi;
            int j=m%divi;
            if(matrix[i][j]==target)return true;
            if(matrix[i][j]<target)l=m+1;
            else
            r=m-1;
        }
        return false;
    }
};