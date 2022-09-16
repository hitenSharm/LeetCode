class Solution {
public:
    // int dp[1000][1000];
    vector<vector<int>> dp;
    int recu(vector<int>& n,vector<int>& m,int l,int i,int r)
    {
        if(i==m.size())return 0;
        if(dp[l][i]!=INT_MIN)return dp[l][i];
        int t1=n[l]*m[i] + recu(n,m,l+1,i+1,r);
        int t2=n[r]*m[i] + recu(n,m,l,i+1,r-1);
        
        return dp[l][i]=max(t1,t2);
    }
    
    int maximumScore(vector<int>& n, vector<int>& m) {
        dp.resize(m.size()+1,vector<int>(m.size(),INT_MIN));
        return recu(n,m,0,0,n.size()-1);
    }
};