// https://leetcode.com/problems/find-k-closest-elements

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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>>p;
        
        for(int i=0;i<arr.size();i++)
        p.push_back({arr[i],x});
        
        partial_sort(p.begin(),p.begin()+k,p.end(),[](pair<int,int>& a,pair<int,int>& b){
            return (abs(a.first-a.second)<abs(b.first-b.second));
        });
        
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(p[i].first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};