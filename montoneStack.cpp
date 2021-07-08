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
    string smallestSubsequence(string s) {
        int vis[26]={0};
        stack<char>st;
        int freq[26]={0};
        
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
        }
        
        for(int i=0;i<s.length();i++)
        {
            while(!st.empty() and s[i]<st.top() and vis[s[i]-'a']==0 and freq[st.top()-'a']>=1)
            {
                vis[st.top()-'a']=0;
                st.pop();
            }
            freq[s[i]-'a']--;
            if(vis[s[i]-'a']==0)
            {
                st.push(s[i]);
                vis[s[i]-'a']=1;
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};