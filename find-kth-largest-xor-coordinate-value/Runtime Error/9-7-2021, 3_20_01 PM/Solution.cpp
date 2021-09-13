// https://leetcode.com/problems/find-kth-largest-xor-coordinate-value

class Solution {
  public:
    int kthLargestValue(vector < vector < int >> & matrix, int k) {
      priority_queue < int, vector < int > , greater < int >> ans;
      int i, j, n = matrix.size(), m = matrix[0].size();
      for (i = 0; i < n; i++) {
        for (j = 1; j < m; j++) {
          matrix[i][j] = matrix[i][j - 1] ^ matrix[i][j];
        }
      }
      for (i = 0; i < m; i++) {
        for (j = 1; j < n; j++) {
          matrix[j][i] = matrix[j - 1][i] ^ matrix[j][i];
        }
      }

      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (ans.size() < k) ans.push(matrix[i][j]);
          else {
            if (ans.top() < matrix[i][j]) {
              ans.pop();
              ans.push(matrix[i][j]);
            }
          }
        }
      }
      return ans.top();
    }
};