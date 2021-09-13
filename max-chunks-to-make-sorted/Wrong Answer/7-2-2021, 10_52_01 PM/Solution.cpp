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
       stack<int>st;
       
       for(int i=0;i<arr.size();i++)
       {
           while(!st.empty() and arr[i]>st.top())
           {
               st.pop();
           }
           if(st.empty())
           chunks++;
           st.push(arr[i]);
       }
       return chunks;
    }
};