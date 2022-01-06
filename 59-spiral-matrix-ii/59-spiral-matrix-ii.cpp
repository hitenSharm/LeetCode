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
    vector<vector<int>> generateMatrix(int n) {
        int i=0,j=0;
        vector<vector<int>>arr(n,vector<int>(n,-1));
        int cnt=1;
        while(cnt<=n*n)
        {
            while(j<n and arr[i][j]==-1)
            {
                arr[i][j]=cnt;
                cnt++;
                j++;
            }
            j--;i++;
            while(i<n and arr[i][j]==-1)
            {
                arr[i][j]=cnt;
                cnt++;
                i++;
            }
            i--;j--;
            while(j>=0 and arr[i][j]==-1)
            {
                arr[i][j]=cnt;
                cnt++;
                j--;
            }
            i--;j++;
            while(i>=0 and arr[i][j]==-1)
            {
                arr[i][j]=cnt;
                cnt++;
                i--;
            }
            i++;j++;
        }
        return arr;
    }
};