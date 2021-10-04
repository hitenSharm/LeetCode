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
    vector<int> searchRange(vector<int>& v, int target) {
        if(v.size()==0)return {-1,-1};
        vector<int>::iterator upper1;
        upper1 =upper_bound(v.begin(), v.end(), target);
        int up=upper1-v.begin();
        up--;
        if((up>=0 and v[up]!=target) || up<0)up=-1;
        
        if(up==-1)return {-1,-1};
        int l=0,r=up;
        int low=up;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(v[m]<target)
            {
                l=m+1;
            }
            else
            {
                low=min(low,m);
                r=m-1;
            }
        }
        return {low,up};
    }
};