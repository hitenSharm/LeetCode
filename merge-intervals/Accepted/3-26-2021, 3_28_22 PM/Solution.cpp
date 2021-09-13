// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector< pair <int,int> > vect;
        int n=intervals.size();
        for (int i=0; i<n; i++)
        vect.push_back( make_pair(intervals[i][0],intervals[i][1]));
        
        sort(vect.begin(), vect.end());
        int j=0;
        stack<int>st;
        stack<int>end;        
        vector<vector<int>>ans;
        while(j<n)
        {
           if(st.empty())
           {
               st.push(vect[j].first);
               end.push(vect[j].second);
               j++;
               continue;
           }
           if(vect[j].first<=end.top())
           {
               if(vect[j].second>end.top())
               {
                   end.pop();
                   end.push(vect[j].second);
               }
               j++;
               continue;
           }
           if(vect[j].first>end.top())
           {
               st.push(vect[j].first);
               end.push(vect[j].second);
               j++;
               continue;      
           }
        }
        while(!st.empty())
        {
            vector<int>temp;
            temp.push_back(st.top());
            temp.push_back(end.top());
            ans.push_back(temp);
            st.pop();
            end.pop();
            temp.clear();
        }
        return ans;
    }
};