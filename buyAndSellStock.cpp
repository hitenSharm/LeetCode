#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
//todo
class Solution {
public:

    int dp[50001][2]={-1};

    int recu(vector<int>& prices,int index,int state,int fee)
    {
      if(index>=prices.size())
        return 0;
      
      if(dp[index][state]!=-1)
        return dp[index][state];

      if(state==1)//buy
      {
        return dp[index][1]=max(recu(prices,index+1,0,fee)+prices[index]-fee,recu(prices,index+1,1,fee));
      }
      if(state==0)
      {
        return dp[index][0]=max(recu(prices,index+1,0,fee),recu(prices,index+1,1,fee)-prices[index]);
      }
      return dp[index][state];
    }

    int maxProfit(vector<int>& prices, int fee) {
        return recu(prices,0,1,fee);
    }
};