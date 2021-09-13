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

    void recu(vector<int>& topping,multiset <int, greater <int> >&p,int cost,int index)
    {
      if(index==topping.size())
      {
        p.insert(cost);
        return ;
      }
      recu(topping,p,cost+topping[index],index+1);
      recu(topping,p,cost+(2*topping[index]),index+1);
      recu(topping,p,cost,index+1);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        multiset <int, greater <int> > possibles;
        recu(toppingCosts,possibles,0,0);
        int ans=INT_MAX;
        int diff=INT_MAX;
        for(int i=0;i<baseCosts.size();i++)
        {
          int temp=target-baseCosts[i];
          if(temp==0)
            return target;
          if(temp<0)
          {
            if(abs(temp)<=diff)
            {              
              if(abs(temp)==diff)ans=min(ans,baseCosts[i]);
              else
                ans=baseCosts[i];
              diff=abs(temp);
            }
          }
          else
          {
            auto it=possibles.lower_bound(temp);
            int tempDiff=baseCosts[i]+(*it);
            if(abs(target-tempDiff)<=diff)
            {              
              if(abs(target-tempDiff)==diff)ans=min(ans,tempDiff);
              else
                ans=tempDiff;
              diff=abs(target-tempDiff);
            }
          }
        }
        return ans;

    }
};