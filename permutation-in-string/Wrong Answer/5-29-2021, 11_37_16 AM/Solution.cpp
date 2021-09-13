// https://leetcode.com/problems/permutation-in-string

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
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>ump;        
        for(char i:s1)
          ump[i]++;

        int i=0;

        unordered_map<char,int>temp=ump;

        while(i<s2.length())
        {
          if(temp.find(s2[i])==temp.end())
          {
            i++;
            temp=ump;
            continue;            
          }
          else
          {
            temp[s2[i]]--;
            if(temp[s2[i]]==0)
              temp.erase(s2[i]);
            i++;
            if(temp.size()==0)
              return true;
            continue;
          }
        }
        return false;
    }
};