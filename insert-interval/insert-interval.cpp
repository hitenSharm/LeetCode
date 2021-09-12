class Solution {
  public:
    vector < vector < int >> insert(vector < vector < int >> & intervals, vector < int > & newInterval) {
      //O(nlogn) approach
      //         vector<vector<int>>ans;
      //         intervals.push_back(newInterval);
      //         sort(intervals.begin(),intervals.end());
      //         int s=intervals[0][0],e=intervals[0][1];

      //         for(int i=1;i<intervals.size();i++)
      //         {
      //             if(e>=newInterval[0])e=max(e,newInterval[1]);
      //             if(intervals[i][0]>e)
      //             {
      //                 ans.push_back({s,e});
      //                 s=intervals[i][0];
      //             }                        
      //             e=max(e,intervals[i][1]);
      //         }
      //         ans.push_back({s,e});
      //O(n) approach
      vector < vector < int >> ans;
      vector < vector < int >> tmp;
      int fl = 0;
      for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] >= newInterval[0] and fl == 0) {
          tmp.push_back(newInterval);
          fl = 1;
          i--;
        } else
          tmp.push_back(intervals[i]);
      }
      if (fl == 0) tmp.push_back(newInterval);
      int s = tmp[0][0], e = tmp[0][1];

      for (int i = 1; i < tmp.size(); i++) {
        if (tmp[i][0] > e) {
          ans.push_back({
            s,
            e
          });
          s = tmp[i][0];
        }
        e = max(e, tmp[i][1]);
      }
      ans.push_back({
        s,
        e
      });
      return ans;

    }
};
