class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 0;
        vector<vector<int>> ans;
        while (i < intervals.size())
        {
            int s = intervals[i][0];
            int e = intervals[i][1];
            while (j < intervals.size() and intervals[j][0] <= e)
            {
                e = max(e, intervals[j][1]);
                j++;
            }
            ans.push_back({ s,e });
            i = j;
        }
        return ans;
    }
};