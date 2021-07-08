#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class StockSpanner {
public:
    StockSpanner(){
    }
    stack<pair<int,int>>st;
    int next(int price) {
        int ans=1;
        while(!st.empty() and price>=st.top().first)
        {
            ans+=st.top().second;
            st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};
//top of stack keeps track of elements that were removed from stack for being smaller than the top element