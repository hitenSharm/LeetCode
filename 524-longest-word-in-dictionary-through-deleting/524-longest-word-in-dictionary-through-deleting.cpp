class Solution {
public:

    bool compare(string& c,string& s)
    {
        int i_candiate=0,i_str=0;
        while(i_str<s.size())
        {
            if(s[i_str]==c[i_candiate])
            {
                i_candiate++;
            }
            i_str++;
        }
        return (i_candiate==c.size() ? true : false);
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(int i=0;i<dictionary.size();++i)
        {
            string candidate=dictionary[i];
            if(compare(candidate,s))
            {
                if(candidate.size()==ans.size() and ans>candidate)ans=candidate;
                else if(ans.size()<candidate.size())ans=candidate;
            }
        }
        return ans;
    }
};