class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        if(numRows==1)return ans;
        ans.push_back({1,1});            
        for(int j=3;j<=numRows;j++)
        {            
            vector<int>na(j,0);
            na[0]=1;
            na[j-1]=1;
            for(int i=1;i<j-1;i++)
            {
                na[i]=ans[j-2][i]+ans[j-2][i-1];
            }
            ans.push_back(na);
        }
        return ans;
    }
};