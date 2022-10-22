class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>>st1;
        stack<pair<char,int>>st2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                st2.push({i,s[i]});
            }
            if(s[i]==')')
            {
                if(!st1.empty() and st1.top().second=='('){
                    st1.pop();
                }else if(!st2.empty()){
                    st2.pop();
                }
                else
                    return false;
            }
            if(s[i]=='(')
            {
                st1.push({i,s[i]});
            }
        }
        if(st1.empty())return true;
        while(!st1.empty() and !st2.empty() and st1.top().first<st2.top().first)
        {
            st1.pop();
            st2.pop();
        }
        return st1.size()==0;
    }
};