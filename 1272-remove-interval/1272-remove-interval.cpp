class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& tbr) {
        vector<vector<int>> ans;
        for(int i=0;i<intervals.size();i++)
        {
            int s=intervals[i][0];
            int e=intervals[i][1];
            
            if(e<tbr[0] || s>tbr[1])
            {
                ans.push_back({s,e});
            }
            else
            {
                if(s<tbr[0])
                {
                    ans.push_back({s,tbr[0]});
                    //s *********************** e
                    //      @@@@@@@@@@@@@@
                    //  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                    //     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                }
                if(e>tbr[1])
                {
                    ans.push_back({tbr[1],e});
                    // s ************************ e
                    // @@@@@@@@@@@@@@@@@@@@
                    //      @@@@@
                    //  @@@@@@@@@@@@@@@@@@@@@@@@@
                }
            }
            
        }
        return ans;
    }
};