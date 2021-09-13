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
        unordered_map<int,int>ump;
        for(int i=0;i<bills.size();i++)
        {          
          if(bills[i]==10)
          {
            if(ump.find(5)!=ump.end())
            {
              ump[5]--;
              if(ump[5]==0)ump.erase(5);
            }
            else
              return false;
          }
          if(bills[i]==20)
          {
            if(ump.find(10)!=ump.end() && ump.find(5)!=ump.end())
            {
              ump[5]--;
              if(ump[5]==0)ump.erase(5);
              ump[10]--;
              if(ump[10]==0)ump.erase(10);
            }
            else if(ump.find(5)!=ump.end() && ump[5]>=3)
            {
              ump[5]=ump[5]-3;
              if(ump[5]==0)ump.erase(5);
            }
            else
              return false;
          }
          ump[bills[i]]++;
        }
        return true;
    }
};