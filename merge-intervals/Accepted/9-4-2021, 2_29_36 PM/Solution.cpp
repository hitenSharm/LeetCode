// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0],e=intervals[0][1];
        int i=1;
        vector<vector<int>>ans;
        while(i<intervals.size())
        {
            if(intervals[i][0]<=e)
                e=max(e,intervals[i][1]);
            else
            {
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
            i++;
        }
        ans.push_back({s,e});
        return ans;
    }
};