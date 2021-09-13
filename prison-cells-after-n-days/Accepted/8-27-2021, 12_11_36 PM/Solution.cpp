// https://leetcode.com/problems/prison-cells-after-n-days

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
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>>ans;        
        vector<int>tmp(8,0);        
        while(n--)
        {
            for(int i=1;i<7;i++)
            {
                if(cells[i-1] ^ cells[i+1]) tmp[i]=0;
                else tmp[i] = 1;
            }
            if(ans.size() and ans.front()==tmp)
                return ans[n%ans.size()];            
            ans.push_back(tmp);
            
            cells=tmp;
        }
        return cells;
    }
};