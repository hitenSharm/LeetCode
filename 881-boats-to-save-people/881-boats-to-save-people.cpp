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
        //nlogn
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
                ans++;
            }
            else
            {
                j--;
                ans++;
            }
        }
        return ans;
    }
};