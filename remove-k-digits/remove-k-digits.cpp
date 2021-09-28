class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        if(num.size()==k)return "0";
        for(int i=0;i<num.size();i++)
        {
            while(!st.empty() and k>0 and num[st.top()]-'0'>num[i]-'0')
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=num[st.top()];
            st.pop();
        }                    
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)ans="0";
        ans.erase(0, min(ans.find_first_not_of('0'), ans.size()-1));        
        return ans;
    }
};