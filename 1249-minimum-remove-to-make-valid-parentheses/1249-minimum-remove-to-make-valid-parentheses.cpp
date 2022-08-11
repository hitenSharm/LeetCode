class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int>st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') {
                st.push_back(i);
            }
            else if (s[i] == ')') {
                if (st.size()>0 and s[st.back()] == '(')
                    st.pop_back();
                else
                    st.push_back(i);
            }
            else
                continue;
        }
        string ans = "";
        int j = 0;        
        for (int i = 0; i < s.size(); i++)
        {
            if (j<st.size() and i == st[j])
            {
                j++;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};