class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        st.push('@');
        for (auto i : s)
        {
            if ((i == ')' and st.top() == '(') || (i == '}' and st.top() == '{') || (i == ']' and st.top() == '[')) {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }
        return st.top() == '@';
    }
};