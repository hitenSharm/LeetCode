// https://leetcode.com/problems/generate-parentheses

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

    void recu(vector<string>&ans,int n,string temp,stack<char>curr)
    {        
        if(n==0 and curr.top()=='@')
        {
            ans.push_back(temp);
            return ;
        }
        if(n<0)
        return ;
        
        if(curr.top()=='(')
        {
            temp=temp+')';
            curr.pop();
            recu(ans,n,temp,curr);
            temp.pop_back();
            curr.push('(');
        }
        
        temp=temp+'(';
        curr.push('(');
        recu(ans,n-1,temp,curr);
        temp.pop_back();
        curr.pop();
    }
    
    vector<string> generateParenthesis(int n) {
        stack<char>curr;
        curr.push('@');
        string temp="";
        vector<string>ans;
        recu(ans,n,temp,curr);
        return ans;
    }
};