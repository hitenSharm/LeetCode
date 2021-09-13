// https://leetcode.com/problems/lemonade-change

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
    bool lemonadeChange(vector<int>& bills) {
        int five=0;int tens=0;
        for(int i=0;i<bills.size();i++)
        {
          if(bills[i]==5)
            five++;
          if(bills[i]==10)
          {
            if(five>0)
            {
              five--;              
            }
            else
              return false;
            tens++;
          }
          if(bills[i]==20)
          {
            if(tens>0 && five>0)
            {
              five--;  
              tens--;
            }
            else if(five>=3)
            {
              five=five-3;              
            }
            else
              return false;
          }          
        }
        return true;
    }
};