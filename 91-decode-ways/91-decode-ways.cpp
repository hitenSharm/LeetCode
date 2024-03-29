class Solution {
public:

    unordered_set<string>valids;
    // int dp[101];
    // int recu(string& s, int i)
    // {
    //     if (i == 0)return 1;
    //     if (dp[i] != -1)return dp[i];
    //     //take one
    //     string s1 = "";
    //     s1 += s[i - 1];
    //     int t1 = 0;
    //     if (valids.find(s1) != valids.end()) {
    //         t1 = recu(s, i - 1);
    //     }
    //     int t2 = 0;
    //     if (i - 2 >= 0) {
    //         string s2 = "";
    //         s2 += s[i - 2];
    //         s2 += s[i - 1];
    //         if (valids.find(s2) != valids.end())
    //         {
    //             t2 = recu(s, i - 2);
    //         }
    //     }
    //     return dp[i] = t1 + t2;
    // }

    int numDecodings(string s) {
        // memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= 26; i++)
        {
            valids.insert(to_string(i));
        }
        int curr=0;
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 1; i <= s.size(); i++)
        {
            string s1 = "";
            s1 += s[i - 1];
            int t1 = 0;
            if (valids.find(s1) != valids.end()) {
                t1 = prev1;
            }
            int t2 = 0;
            if (i - 2 >= 0) {
                string s2 = "";
                s2 += s[i - 2];
                s2 += s[i - 1];
                if (valids.find(s2) != valids.end())
                {
                    t2 = prev2;
                }
            }
            curr = t1+t2;
            int temp = prev1;
            prev1 = curr;
            prev2 = temp;
        }
        return curr;
    }
};