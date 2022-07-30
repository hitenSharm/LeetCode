class Solution {
public:
    
    int solve(int& t1,int& t2,string& t)
    {
        if(t=="+")
            return t2+t1;
        if(t=="-")
            return t2-t1;
        if(t=="/")
            return t2/t1;
        if(t=="*")
            return t2*t1;
        return 0;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                int ans=solve(t1,t2,tokens[i]);
                st.push(ans);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};