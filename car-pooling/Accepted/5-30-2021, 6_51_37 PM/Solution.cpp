// https://leetcode.com/problems/car-pooling

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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int loactions[1001]={0};
        int mxLoacltion=0;int minLocation=1001;
        for(int i=0;i<trips.size();i++)
        {
          int stLoaction=trips[i][1];
          int enLoaction=trips[i][2];
          int cap=trips[i][0];
          loactions[stLoaction]+=cap;
          loactions[enLoaction]=loactions[enLoaction]-cap;
          mxLoacltion=max(mxLoacltion,enLoaction);
          minLocation=min(minLocation,stLoaction);
        }

        for(int i=minLocation;i<=mxLoacltion;i++)
        {
          loactions[i]=loactions[i-1]+loactions[i];
          if(loactions[i]>capacity)
            return false;
        }
        return true;
    }
};