class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        if(secondList.size()==0 || firstList.size()==0)return {};
        vector<vector<int>>ans;
        while(i<firstList.size() and j<secondList.size())
        {
            int st,en;
            if(firstList[i][1]<secondList[j][0])
            {
                i++;
                continue;
            }
            if(firstList[i][0]>secondList[j][1])
            {
                j++;
                continue;
            }
            st=max(firstList[i][0],secondList[j][0]);
            en=min(firstList[i][1],secondList[j][1]);
            if(en==firstList[i][1])i++;
            if(en==secondList[j][1])j++;
            ans.push_back({st,en});
        }
        return ans;
    }
};