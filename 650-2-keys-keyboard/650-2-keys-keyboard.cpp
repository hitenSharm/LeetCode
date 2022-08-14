class Solution {
public:
    int dp[1002][1002];
    int recu(int aCnt, int copy, int paste,int& n)
    {
        if (aCnt > n)return 1001;
        if (aCnt == n)return 0;
        if(dp[copy+1][paste+1]!=-1)return dp[copy+1][paste+1];
        if (copy == -1) {
            return dp[copy+1][paste+1]=1 + recu(aCnt, aCnt, paste, n);
        }
        else
        {
            if (paste == -1)
            {
                return dp[copy+1][paste+1]=1 + recu(aCnt+copy, copy, copy, n);
            }
            return dp[copy+1][paste+1]=min(1 + recu(aCnt, aCnt, -1, n), 1 + recu(aCnt + copy, copy, copy, n));
        }

    }

    int minSteps(int n) {
        
        int a = 1;
        memset(dp,-1,sizeof(dp));
        return recu(a, -1, -1, n);
    }
};