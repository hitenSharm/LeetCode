class Solution {
public:
    
    vector<long long int>dp;

    long long int interchangeableRectangles(vector<vector<int>>& rectangles) {
        dp.resize(rectangles.size());
        dp[0]=1;
        dp[1]=1;
        unordered_map<double,long long int>ump;
        for(long long int i=0;i<rectangles.size();++i)
        {
            dp[i]= (i>1 ? dp[i-1]+i : i);
            double x=rectangles[i][0]*1.0;
            ump[x/rectangles[i][1]]++;
        }
        long long int ans=0;
        for(auto it:ump)
        {
            ans+=dp[it.second-1];
        }
        return ans;
    }
};