class Solution {
public:

    bool valid(unordered_map<char, int>& f, unordered_map<char, int>& u)
    {
        for (auto it : u)
        {
            if (f.find(it.first) == f.end() || f[it.first] < it.second)return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int>ump;
        
        for (auto i : t)ump[i]++;

        int i = 0,j=0;
        unordered_map<char, int>freq;
        int ans[2]={-1,-1};
        int len = INT_MAX;
        while (i < s.size())
        {            
            while (j < s.size() and !valid(freq, ump))
            {
                freq[s[j]]++;                
                j++;
            }
            if (valid(freq, ump))
            {
                if (len > j - i) {
                    len = j - i;
                    ans[0] = i;
                    ans[1] = j - 1;
                }
            }
            freq[s[i]]--;
            i++;
        }        
        i = ans[0];
        j = ans[1];
        if(i==-1)return "";
        string res = "";
        for (; i <= j; i++)
            res += s[i];
        return res;
    }
};