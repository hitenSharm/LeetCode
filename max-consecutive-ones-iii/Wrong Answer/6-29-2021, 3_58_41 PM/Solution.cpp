// https://leetcode.com/problems/max-consecutive-ones-iii

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
        while(i<nums.size())
        {
            while(j<nums.size() and k>=0)
            {
                if(nums[j]==0 and k==0)break;
                if(nums[j]==0)
                k--;                
                j++;
            }
            //cout<<i<<" i and j "<<j<<endl;
            len=max(len,j-i);
            if(nums[i]==0)
            k++;
            i++;
            if(i>j)
                j=i;
        }
        return len;
    }
};