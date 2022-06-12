class Solution {
public:
    int dp[5001][2][2];
    int recu(int i,vector<int>& p,int byOrsell,int c)
    {
        if(i==p.size())return 0;
        if(dp[i][byOrsell][c]!=-1)return dp[i][byOrsell][c];
        if(c==1)
        {
            return recu(i+1,p,0,0);
        }
        int ans=recu(i+1,p,byOrsell,c);
        if(byOrsell==0)
        {
            //buy
            int t1=recu(i+1,p,1,c)-p[i];
            ans=max(ans,t1);
        }
        else
        {
            int t2=recu(i+1,p,0,1)+p[i];
            ans=max(ans,t2);
        }
        return dp[i][byOrsell][c]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        int x = recu(0,prices,0,0);        
        if(x<0)x=0;
        return x;
    }
};