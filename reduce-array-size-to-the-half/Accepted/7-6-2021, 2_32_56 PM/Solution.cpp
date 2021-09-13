// https://leetcode.com/problems/reduce-array-size-to-the-half

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

    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return (a.second>b.second);
    }

    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>ump;
        for(int i=0;i<arr.size();i++)
        ump[arr[i]]++;
        
        vector<pair<int,int>>vec(ump.begin(),ump.end());
        sort(vec.begin(),vec.end(),cmp);
        int ele=arr.size();
        int cnt=0;
        for(int i=0;i<vec.size();i++)
        {
            if(ele<=arr.size()/2)
            break;
            cnt++;
            ele=ele-vec[i].second;
        }
        return cnt;
    }
};