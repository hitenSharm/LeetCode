class Solution {
public:

    static bool comp(pair<int,int>& p1,pair<int,int>& p2)
    {
        return p1.second>p2.second;
    }

    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>arr;
        for(int i=0;i<plantTime.size();i++)
        {
            arr.push_back({plantTime[i],growTime[i]});
        }
        sort(arr.begin(),arr.end(),comp);
        int ans=0;
        int planting=0;
        for(auto it:arr)
        {
            planting+=it.first;//add planting time as we cant plant a new when planting something already
            ans=max(ans,planting+it.second);//when planting new+time that will take to grow;
        }
        return ans;
    }
};