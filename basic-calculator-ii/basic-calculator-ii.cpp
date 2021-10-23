class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char prevChar='+';
        for(int i=0;i<s.length();)
        {            
            if(s[i]==' ')i++;
            else if(isdigit(s[i]))
            {
                string temp="";
                while(i<s.length() and (isdigit(s[i]) || s[i]==' '))
                {
                    if(s[i]==' ')
                    {
                        i++;
                        continue;
                    }
                    temp+=s[i];
                    i++;
                }
                int tmp=atoi(temp.c_str());
                if(prevChar=='-')tmp=tmp*(-1);
                st.push(tmp);
            }
            else if(s[i]=='+')
            {
                prevChar='+';
                i++;
                continue;
            }
            else if(s[i]=='-')
            {
                prevChar='-';
                i++;
                continue;
            }
            else
            {
                prevChar=s[i];
                int t1=st.top();
                st.pop();
                i++;
                string temp="";
                while(i<s.length() and (isdigit(s[i]) || s[i]==' '))
                {
                    if(s[i]==' ')
                    {
                        i++;
                        continue;
                    }
                    temp+=s[i];
                    i++;
                }
                int t2=atoi(temp.c_str());
                if(prevChar=='/')t2=t1/t2;
                else
                t2=t1*t2;
                st.push(t2);
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};