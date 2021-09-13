// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,int>ump;
        vector< pair <int,int> > vect;
        for(int i=0;i<points.size();i++)
        {
            int tsum=0;
            for(int j=0;j<points[i].size();j++)
            {
                tsum+=points[i][j]*points[i][j];
            }
            vect.push_back( make_pair(tsum,i));
        }
        partial_sort(vect.begin(),vect.begin()+k,vect.end());
        vector<vector<int>>ans;
        for(int i=0;i<k;i++)
        {
            int index=vect[i].second;
            vector<int>temp;
            temp.push_back(points[index][0]);
            temp.push_back(points[index][1]);
            ans.push_back(temp);
        }
        
        return ans;
    }
};