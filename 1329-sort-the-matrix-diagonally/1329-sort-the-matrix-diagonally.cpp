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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int vis[101][101]={0};
        priority_queue<int>pq;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(vis[i][j]==1)continue;
                int ti=i,tj=j;
                while(ti<mat.size() and tj<mat[0].size())
                {
                    vis[ti][tj]=1;
                    pq.push(mat[ti][tj]);
                    ti++;
                    tj++;
                }
                ti--;
                tj--;
                while(ti>=0 and tj>=0 and !pq.empty())
                {
                    mat[ti][tj]=pq.top();
                    pq.pop();
                    ti--;
                    tj--;
                }
            }
        }
        return mat;
    }
};