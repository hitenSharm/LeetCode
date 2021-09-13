// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

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
        vector<int>ans;
        stack<int>st;
        
        for(int i=0;i<prices.size();i++)
        {
            vector<int>temp;
            while(!st.empty() and st.top()>=prices[i])
            {
                temp.push_back(st.top()-prices[i]);
                st.pop();
            }
            for(int j=temp.size()-1;j>=0;j--)
            {
                ans.push_back(temp[j]);
            }
            st.push(prices[i]);
        }
        vector<int>temp;
        while(!st.empty())
        {
            temp.push_back(st.top());
            st.pop();
        }
        for(int j=temp.size()-1;j>=0;j--)
        {
            ans.push_back(temp[j]);
        }
        return ans;
    }
};