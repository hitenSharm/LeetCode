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
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<colors.size()-1;)
        {
            char curr=colors[i];
            pq.push(neededTime[i]);
            i++;
            while(i<colors.size() and colors[i]==curr)
            {
                pq.push(neededTime[i]);
                i++;
            }
            while(pq.size()>1)
            {
                ans+=pq.top();
                pq.pop();
            }
            pq.pop();
        }
        return ans;
    }
};