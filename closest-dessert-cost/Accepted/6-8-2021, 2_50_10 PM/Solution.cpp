// https://leetcode.com/problems/closest-dessert-cost

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
    struct Comp {
    bool operator()(const int& num1, const int& num2) {
        if(abs(num1) < abs(num2)) {
            return true;
        }
        
        if(abs(num1) == abs(num2)) {
            return num1 < num2;
        }
        
        return false;
    }
};

    vector<vector<int>> dp;

    int recu(vector<int>& topping,int cost,int index)
    {
      if(index==topping.size() || cost<0)
      {
        return -cost;
      }

      if(dp[index][cost]!=INT32_MAX)
        return dp[index][cost];

      int t1=recu(topping,cost-topping[index],index+1);
      int t2=recu(topping,cost-(2*topping[index]),index+1);
      int t3=recu(topping,cost,index+1);
      vector<int> nums = {t1, t2, t3};
      sort(nums.begin(),nums.end(),Comp());

      return dp[index][cost]=nums[0];
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans=INT_MAX;
        int diffCurr=INT_MAX;
        dp.resize(toppingCosts.size(), vector<int>(target, INT32_MAX));
        for(int i=0;i<baseCosts.size();i++)
        {
          int topping=target-baseCosts[i];
          int diff=recu(toppingCosts,topping,0);
          int newCost=target+diff;
          if(abs(target - newCost)<diffCurr)
          {
            diffCurr=abs(target - newCost);
            ans=newCost;
          }
          else if(abs(target - newCost)==diffCurr)
            ans=min(ans,newCost);
        }
        return ans;

    }
};