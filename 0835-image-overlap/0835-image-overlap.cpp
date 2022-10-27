class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        //vote on offset
        vector<vector<int>>v1;
        vector<vector<int>>v2;
        for(int i=0;i<img1.size();i++)
        {
            for(int j=0;j<img1.size();j++)
            {
                if(img1[i][j]==1){
                    v1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    v2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int>ump;
        int maxi=0;
        for(auto i:v1)
        {
            for(auto j:v2)
            {
                ump[{j[0]-i[0],j[1]-i[1]}]++;
                maxi=max(maxi,ump[{j[0]-i[0],j[1]-i[1]}]);
            }
        }
        return maxi;
    }
};