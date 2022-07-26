class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //basically check if does a meeting end before another starts
        //if another has to start so room++;
        //divide into 2 arrays and check
        vector<int>arr;
        vector<int>dep;
        for(int i=0;i<intervals.size();i++)
        {
            arr.push_back(intervals[i][0]);
            dep.push_back(intervals[i][1]);
        }
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int rooms=INT_MIN;
        int i=0,j=0;
        while(j<dep.size())
        {            
            while(i<arr.size() and dep[j]>arr[i])//meeting hasnt ended and a meeting starts
            {
                i++;
            }
            rooms=max(rooms,i-j);
            j++;
        }
        return rooms;
    }
};