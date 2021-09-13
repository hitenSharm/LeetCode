// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>req(26,0);
        for(char i :p)
        {
            req[i-'a']++;
        }
        int i=0;
        int j=0;
        vector<int>sol(26,0);
        vector<int>ans;
        while(j<s.length())
        {
            while(j-i<p.length()&&j<s.length())
            {
                sol[s[j]-'a']++;
                j++;
            }
            if(sol==req)
            {
                ans.push_back(i);
            }
            sol[s[i]-'a']--;
            i++;
        }
        return ans;
    }
};