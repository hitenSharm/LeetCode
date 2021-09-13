// https://leetcode.com/problems/construct-k-palindrome-strings

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
    bool canConstruct(string s, int k) {
        unordered_map<char,int>ump;
        for(char i:s)
        {
          ump[i]++;
        }
        int ev=0;int od=0;
        for(auto it:ump)
        { 
           
          int temp=it.second;           
          if((temp | 1) > temp)
            ev++;
          else
          {
            if(temp>1)
              ev=ev+temp/2;
            od++;
          }
        }        
        int maxi=s.length();
        int mini;
        if(ev==0)
        {          
          mini=od;
        }
        else if(od==0)
        {          
          mini=1;
        }
        else if(od!=0 && ev!=0)
        {          
          if(od>=ev)
            mini=max(od,ev);
          else
          {
            mini=min(ev,od);
          }
        }
        if(k<=maxi and k>=mini)
          return true;
        return false;
    }
};