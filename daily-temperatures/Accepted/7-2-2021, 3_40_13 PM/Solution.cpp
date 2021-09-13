// https://leetcode.com/problems/daily-temperatures

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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>indexes;
        stack<int>st;
        vector<int>ans(temperatures.size(),0);
        
        for(int i=0;i<temperatures.size();i++)
        {
            while(!st.empty() and st.top()<temperatures[i])
            {
                ans[indexes.top()]=i-indexes.top();
                indexes.pop();
                st.pop();
            }
            st.push(temperatures[i]);
            indexes.push(i);
        }
        return ans;
    }
};