// https://leetcode.com/problems/max-chunks-to-make-sorted

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
    int maxChunksToSorted(vector<int>& arr) {
       int chunks=0;
       int miniReq=0,maxi=0;
       
       for(int i=0;i<arr.size();i++)
       {
           maxi=max(maxi,arr[i]);
           //cout<<miniReq<<" ";
           if(arr[i]==miniReq)
           {
               chunks++;
               miniReq=maxi+1;               
           }           
       }
       return chunks;
    }
};