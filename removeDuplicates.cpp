#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push('@');
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans="";
        while(st.top()!='@')
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};