class Solution {
public:
    int dp[300][11];
    int recu(vector<int>& jd,int days,int idx)
    {
        if(idx>=jd.size() and days>=1)return 30001; //this means invalid 
        if(days==1)
        {
            int ans=INT_MIN;
            for(int i=idx;i<jd.size();i++)
            {
                ans=max(ans,jd[i]);
            }
            return ans;
        }
        if(dp[idx][days]!=-1)return dp[idx][days];
        int ans=INT_MAX;
        int curr=0;
        for(int i=idx;i<jd.size();i++)
        {
            curr=max(curr,jd[i]);
            ans=min(ans,curr+recu(jd,days-1,i+1));
        }
        return dp[idx][days]=ans;
    }
    
    int minDifficulty(vector<int>& jd, int d) {
        if(jd.size()<d)return -1;
        memset(dp,-1,sizeof(dp));
        return recu(jd,d,0);
    }
};