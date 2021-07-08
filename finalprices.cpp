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
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>ans(prices.size());
        stack<int>st;
        stack<int>indexes;
        for(int i=0;i<prices.size();i++)
        {
            while(!st.empty() and st.top()>=prices[i])
            {
                ans[indexes.top()]=st.top()-prices[i];
                st.pop();
                indexes.pop();
            }
            st.push(prices[i]);
            indexes.push(i);
        }
        
        while(!st.empty())
        {
            ans[indexes.top()]=st.top();
            st.pop();
            indexes.pop();
        }
        
        return ans;
    }
};