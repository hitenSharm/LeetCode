// https://leetcode.com/problems/boats-to-save-people

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
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int boats=0;
        while(i<=j)
        {
          if (people[i]+people[j]<=limit)
          {
            i++;
            j--;
            boats++;
            continue;
          }
          if(people[i]+people[j]>limit)
          {
            j--;
            boats++;
            continue;            
          }
        }
        return boats;
    }
};