// https://leetcode.com/problems/maximum-units-on-a-truck

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

    bool static comp(vector<int> &x,vector<int> &y){
        return (x[1]>y[1]);
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),comp);
        int ans=0;
        int boxes=0;
        for(int i=0;i<boxTypes.size();i++)
        {
          if(boxes+boxTypes[i][0]<=truckSize)
          {
            boxes+=boxTypes[i][0];
            ans+=(boxTypes[i][0]*boxTypes[i][1]);
          }
          else
          {
            ans+=((truckSize-boxes)*boxTypes[i][1]);
            break;
          }
        }
        return ans;
    }
};