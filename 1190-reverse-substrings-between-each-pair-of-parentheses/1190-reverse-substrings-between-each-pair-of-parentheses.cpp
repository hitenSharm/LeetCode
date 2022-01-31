class Solution {
public:
    string reverseParentheses(string s) {
        deque<char>dq;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=')')dq.push_back(s[i]);
            else
            {
                string tmp="";
                while(dq.back()!='(')
                {
                    tmp+=dq.back();
                    dq.pop_back();
                }
                dq.pop_back();
                for(int j=0;j<tmp.size();j++)dq.push_back(tmp[j]);
            }
        }
        string ans="";
        while(!dq.empty())
        {
            if(dq.front()!='(' || dq.front()!=')')
            ans+=dq.front();
            dq.pop_front();
        }
        return ans;
    }
};