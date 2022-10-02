class Solution {
public:
    int mod = 1e9 + 7;
    int dp[31][1001];
    int recu(int n, int& k, int& t, int cSum)
    {
        if (n == 0)
        {
            if (cSum == t)return 1;
            return 0;
        }
        if (dp[n][cSum] != -1)return dp[n][cSum];
        int ways = 0;
        for (int i = 1; i <= k; i++)
        {
            if (cSum + i > t)break;
            ways += recu(n - 1, k, t, cSum + i);
            ways%=mod;
        }
        return dp[n][cSum] = ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp, -1, sizeof(dp));
        return recu(n, k, target, 0);
    }
};