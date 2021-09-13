// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector< pair <int,int> > vect;
        int n=intervals.size();
        for (int i=0; i<n; i++)
        vect.push_back( make_pair(intervals[i][0],intervals[i][1]));
        
        sort(vect.begin(), vect.end());
        int s=0;
        int i=0;
        int j=i+1;
        vector<vector<int>>ans;
        while(j<n)
        {
            if(vect[i].second>=vect[j].first)
            {
                i++;
                j++;                
            }
            else
            {
                vector<int>temp;
                temp.push_back(vect[s].first);
                temp.push_back(vect[i].second);
                ans.push_back(temp);
                temp.clear();
                i++;
                j++;
                s=i;
            }
        }
        vector<int>temp;
                temp.push_back(vect[s].first);
                temp.push_back(vect[i].second);
                ans.push_back(temp);
                temp.clear();
        return ans;
    }
};