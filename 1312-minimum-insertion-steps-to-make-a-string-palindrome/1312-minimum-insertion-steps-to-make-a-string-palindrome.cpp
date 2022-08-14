class Solution {
public:

    vector<vector<int>>dp;

    //     int lcs(string& s1, string& s2, int i, int j)
    //     {
    //         if (i == 0 || j == 0)return 0;

    //         if (s1[i-1] == s2[j-1])
    //         {
    //             return 1 + lcs(s1, s2, i - 1, j - 1);
    //         }

    //         return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
    //     }

    int minInsertions(string s) {
        dp.resize(s.size() + 1, vector<int>(s.size() + 1, 0));
        //s-lcs(s,rev(s))
        //i basically want to make s=reverse(s) in min insertions
        //so thats like get the lcs, and sub from strlen
        string temp = s;
        reverse(s.begin(), s.end());
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                if (temp[i - 1] == s[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return s.size() - dp[s.size()][s.size()];
    }
};