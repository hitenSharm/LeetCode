// https://leetcode.com/problems/kth-missing-positive-number

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
    int findKthPositive(vector<int>& arr, int k) {
        int maxi=1;
        for(int i=0;i<arr.size();i++)
        {            
            if(arr[i]!=maxi)
            {
              k=k-(arr[i]-maxi);                 
              if(k<=0)
              {
                  return ((i-1>=0 ? arr[i-1] : 0)+(k+(arr[i]-maxi)));
              }
            }
            maxi=arr[i]+1;
        }
        return arr[arr.size()-1]+k;
    }
};