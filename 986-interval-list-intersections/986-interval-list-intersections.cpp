class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(secondList.size()==0 || firstList.size()==0)return {};
        vector<vector<int>>ans;
        int i=0,j=0;        
        while(i<firstList.size() and j<secondList.size())
        {
            int start=max(firstList[i][0],secondList[j][0]);
            int ending=min(firstList[i][1],secondList[j][1]);
            if(start<=ending){
                ans.push_back({start,ending});
            }
            if(ending == secondList[j][1]){
                j++;
            }
            else if(ending == firstList[i][1]){
                i++;
            }
        }
        return ans;
    }
};