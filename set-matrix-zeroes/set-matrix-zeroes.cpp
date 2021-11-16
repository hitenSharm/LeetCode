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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>zeros;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)zeros.push_back({i,j});
            }
        }
        for(int i=0;i<zeros.size();i++)
        {
            pair<int,int>&t=zeros[i];
            int ti=t.first-1;
            int tj=t.second;
            while(ti>=0)
            {
                matrix[ti][tj]=0;
                ti--;
            }
            ti=t.first+1;
            while(ti<matrix.size())
            {
                matrix[ti][tj]=0;
                ti++;
            }
            ti=t.first;
            tj=t.second-1;
            while(tj>=0)
            {
                matrix[ti][tj]=0;
                tj--;
            }
            tj=t.second+1;            
            while(tj<matrix[0].size())
            {
                matrix[ti][tj]=0;
                tj++;
            }
        }
    }
};