// https://leetcode.com/problems/valid-parentheses

#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        st.push('*');
        for(int i=0;i<s.length();i++)
        {
            char temp=st.top();
            if(temp=='(' && s[i]==')')
            {
                st.pop();
                continue;
            }
            if(temp=='{' && s[i]=='}')
            {
                st.pop();
                continue;
            }
            if(temp=='[' && s[i]==']')
            {
                st.pop();
                continue;
            }
            else
            st.push(s[i]);
        }
        if(st.top()=='*')
        return true;
        
        return false;
    }
};