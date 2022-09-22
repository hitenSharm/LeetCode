class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& tbr) {
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();i++)
        {
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s==tbr[0] and e>tbr[1])
            {
                int ts=tbr[1];
                int te=e;
                ans.push_back({ts,te});
            }
            else if(s<tbr[0] and e>tbr[1])
            {
                int ts=s;
                int te=tbr[0];
                ans.push_back({ts,te});
                ts=tbr[1];
                te=e;
                ans.push_back({ts,te});
            }
            else if(e==tbr[1] and s<tbr[0])
            {
                int ts=s;
                int te=tbr[0];
                ans.push_back({ts,te});
            }
            else if(e<tbr[0] || s>tbr[1])
            {
                ans.push_back({s,e});
            }
            else if(s<=tbr[1] and e>tbr[1])
            {
                int ts=tbr[1];
                int te=e;
                ans.push_back({ts,te});
            }
            else if(s<tbr[0] and e>=tbr[0])
            {
                int ts=s;
                int te=tbr[0];
                ans.push_back({ts,te});
            }
        }
        return ans;
    }
};