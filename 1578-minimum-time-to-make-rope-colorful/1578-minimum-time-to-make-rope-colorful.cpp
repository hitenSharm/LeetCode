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
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;       
        //can be done with sliding winodw , we want the smallest n-1 elements from a winodw of size n
        //add all and keep track f maximum
        int i=0,j=0;
        while(i<colors.size())
        {
            int maxi=0;
            while(j<colors.size() and colors[j]==colors[i])
            {
                ans+=neededTime[j];
                maxi=max(maxi,neededTime[j]);
                j++;
            }
            ans-=maxi;
            i=j;
        }
        return ans;
    }
};