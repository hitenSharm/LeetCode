class Solution {
public:
    
    vector<vector<int>>dp;
    
    int f(int i,int j,vector<int>& cuts)
    {
        if(i>j)return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            int temp=cuts[j+1]-cuts[i-1]+ f(i,k-1,cuts) + f(k+1,j,cuts);
            ans=min(ans,temp);
        }        
        return dp[i][j]=ans;
    }
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.resize(cuts.size(),vector<int>(cuts.size(),-1));
        return f(1,cuts.size()-2,cuts);
        
    }
};