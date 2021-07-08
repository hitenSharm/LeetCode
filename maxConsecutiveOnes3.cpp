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
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,len=0;
        int t=k;
        while(i<nums.size())
        {
            while(j<nums.size() and t>=0)
            {
                if(nums[j]==0 and t==0)break;
                if(nums[j]==0)
                t--;                
                j++;
            }
            len=max(len,j-i);
            if(nums[i]==0 and t<k)
            t++;
            i++;
            if(i>j)
                j=i;
        }
        return len;
    }
};