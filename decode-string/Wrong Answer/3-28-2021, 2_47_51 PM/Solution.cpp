// https://leetcode.com/problems/decode-string

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=s.length()-1;i>=0;)
        {
            string str;
            if(s[i]=='[')
            {                
                string temp="";
                while(st.top()!="]")
                {
                    temp=temp+st.top();
                    st.pop();
                }
                int repe=s[i-1]-'0';                
                string t2=temp;
                for(int i=1;i<repe;i++)
                {
                    temp=temp+t2;
                }
                st.pop();
                st.push(temp);
                i=i-2;
                continue;
            }
            str+=s[i];
            st.push(str);   
            i--;                     
        }
        string ans="";
        while(!st.empty())
         {
            ans=ans+st.top();
            st.pop();
         }
         return ans;

    }
};