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
                int k=i-1;
                int curr=0;
                int repe=0;                
                while(k>=0 && s[k]>='0' && s[k]<='9')
                {
                    int x=s[k]-'0';
                    repe=repe+(x*pow(10,curr));
                    curr++;
                    k--;
                }                                
                string t2=temp;
                for(int j=1;j<repe;j++)
                {
                    temp=temp+t2;
                }
                st.pop();
                st.push(temp);                
                i=k;
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