class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int i=0,j=0;        
        vector<vector<int>>ans;
        while(i<intervals.size())
        {           
            int ending=intervals[i][1];             
            while(j<intervals.size() and intervals[j][0]<=ending)
            {
                ending=max(intervals[j][1],ending);
                j++;
            }
            ans.push_back({intervals[i][0],ending});
            i=j;
        }
        return ans;
    }
};