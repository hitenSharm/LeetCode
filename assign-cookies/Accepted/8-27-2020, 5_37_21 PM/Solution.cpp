// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int k = 0;
        for (int i = 0; i < s.size(); i++) {
            if (k < g.size() && s[i] >= g[k]) {
                k++;
            }
        }
        return k;
        
    }
};