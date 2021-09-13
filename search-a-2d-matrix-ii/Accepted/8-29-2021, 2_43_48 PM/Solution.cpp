// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        while(j>=0 and i<matrix.size())
        {
            if(target==matrix[i][j])return true;
            if(target>matrix[i][j])
            {
                i++;
            }
            else
                j--;
        }
        return false;
    }
};