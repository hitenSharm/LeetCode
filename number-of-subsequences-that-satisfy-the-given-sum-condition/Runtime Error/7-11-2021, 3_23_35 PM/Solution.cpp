// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

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
    int numSubseq(vector<int>& nums, int target) {
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(2*nums[i]>target)break;
            else
            {
                int l=i,r=nums.size()-1;
                int j=i;
                while(l<=r)
                {
                    int m=l+(r-l)/2;
                    if(nums[m]+nums[i]>target)
                    {
                        r=m-1;
                    }
                    else
                    {
                        j=m;
                        l=m+1;
                    }
                }
                if(nums[i]*2<=target)
                ans+= 1 << (j-i);
                else
                ans+= (1<<(j-i))-1;
            }
        }
        return ans;
    }
};