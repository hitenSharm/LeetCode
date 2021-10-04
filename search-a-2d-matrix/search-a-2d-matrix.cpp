#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()*matrix[0].size()-1;
        int n=matrix[0].size();
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int i=m/n;
            int j=m-(i*n);
            if(matrix[i][j]<target)
            {
                l=m+1;
            }
            else if(matrix[i][j]>target)
            {
                r=m-1;
            }
            else
            return true;
        }
        return false;
    }
};