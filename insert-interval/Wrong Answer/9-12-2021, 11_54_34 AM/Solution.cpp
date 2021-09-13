// https://leetcode.com/problems/insert-interval

class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        if(intervals.size()==0 || newInterval[0]<=intervals[0][0])
        {
            int s=newInterval[0],e=newInterval[1];
            for(int i=0;i<intervals.size();i++)
            {
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
        
        if(newInterval[0]>=intervals[intervals.size()-1][1])intervals.push_back(newInterval);
        
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
        if(e>=newInterval[0])e=max(e,newInterval[1]);
        ans.push_back({s,e});
        return ans;
    }
};