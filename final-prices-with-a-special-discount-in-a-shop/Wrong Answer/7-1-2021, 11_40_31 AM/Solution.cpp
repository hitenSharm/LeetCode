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
        queue<int>q;
        
        for(int i=0;i<prices.size();i++)
        {
            while(!q.empty() and q.front()>=prices[i])
            {
                ans.push_back(q.front()-prices[i]);
                q.pop();
            }
            q.push(prices[i]);
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};