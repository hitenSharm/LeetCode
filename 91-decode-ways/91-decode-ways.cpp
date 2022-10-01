class Solution {
public:

    unordered_set<string>valids;
    int dp[100];
    int recu(string& s, int i)
    {
        if (i >= s.size())return 1;
        if (dp[i] != -1)return dp[i];
        //take one
        string s1 = "";
        s1 += s[i];
        int t1 = 0;
        if (valids.find(s1) != valids.end()) {
            t1 = recu(s, i + 1);
        }
        int t2 = 0;
        if (i + 1 < s.size()) {
            string s2 = "";
            s2 += s[i];
            s2 += s[i + 1];
            if (valids.find(s2) != valids.end())
            {
                t2 = recu(s, i + 2);
            }
        }
        return dp[i]=t1 + t2;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= 26; i++)
        {
            valids.insert(to_string(i));
        }
        return recu(s, 0);
    }
};