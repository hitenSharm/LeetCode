// https://leetcode.com/problems/insert-interval

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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        vector<vector<int>>tmp;
        int fl=0;        
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]>=newInterval[0] and fl==0)
            {
                tmp.push_back(newInterval);
                fl=1;
                i--;
            }
            else
            tmp.push_back(intervals[i]);
        }
        if(fl==0)tmp.push_back(newInterval);
        int s=tmp[0][0],e=tmp[0][1];
        
        for(int i=1;i<tmp.size();i++)
        {
            if(tmp[i][0]>e)
            {
                ans.push_back({s,e});
                s=tmp[i][0];
            }                        
            e=max(e,tmp[i][1]);
        }
        ans.push_back({s,e});
        return ans;
    }
};