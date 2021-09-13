// https://leetcode.com/problems/insert-interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0],e=intervals[0][1];
        
        for(int i=1;i<intervals.size();i++)
        {
            if(e>=newInterval[0])e=max(e,newInterval[1]);
            if(intervals[i][0]>e)
            {
                ans.push_back({s,e});
                s=intervals[i][0];
            }                        
            e=max(e,intervals[i][1]);
        }
        ans.push_back({s,e});
        return ans;
    }
};