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
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int add;
        while(numBottles>0 && numBottles>=numExchange)
        {
          add=numBottles/numExchange;
          numBottles=numBottles-(numExchange*add);
          ans=ans+numExchange*add;
          numBottles=numBottles+add;            
        }
        return ans+numBottles;
    }
};