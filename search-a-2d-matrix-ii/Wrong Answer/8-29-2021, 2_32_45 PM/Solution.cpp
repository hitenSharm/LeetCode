// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0;
        int r=matrix[0].size()-1;        
        int i=0;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(matrix[0][m]<target)
            {
                l=m+1;
                i=m;
            }
            if(matrix[0][m]>target)
                r=m;
            if(matrix[0][m]==target)
                return true;            
        }
        l=0;r=matrix.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(matrix[m][i]<target)
                l=m+1;
            if(matrix[m][i]>target)
                r=m;
            if(matrix[m][i]==target)
                return true;
        }
        return false;
    }
};