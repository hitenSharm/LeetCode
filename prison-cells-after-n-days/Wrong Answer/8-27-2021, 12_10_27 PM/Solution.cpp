// https://leetcode.com/problems/prison-cells-after-n-days

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>>ans;        
        vector<int>tmp(8,0);        
        for(int j=0;j<n;j++)
        {
            for(int i=1;i<7;++i)
            {
                tmp[i] = (cells[i-1]==cells[i+1]);
            }
            if(ans.size() and ans.front()==tmp)
                return ans[n%ans.size()];            
            ans.push_back(tmp);
            
            cells=tmp;
        }
        return cells;
    }
};