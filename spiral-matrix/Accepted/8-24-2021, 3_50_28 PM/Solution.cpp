// https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0,j=0;
        vector<int>ans;
        int cnt=0;
        while(cnt<(matrix.size()*matrix[0].size()))
        {
            while(j<matrix[i].size() and matrix[i][j]!=-101)
            {
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-101;
                j++;
                cnt++;
            }
            j--;
            i++;
            while(i<matrix.size() and matrix[i][j]!=-101)
            {
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-101;
                i++;
                cnt++;
            }
            i--;
            j--;
            while(j>=0 and matrix[i][j]!=-101)
            {
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-101;
                j--;
                cnt++;
            }
            j++;
            i--;
            while(i>=0 and matrix[i][j]!=-101)
            {
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-101;
                i--;
                cnt++;
            }
            i++;
            j++;
        }
        return ans;
    }
};