// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum

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
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int i=0,j=0;
        multiset<int>ele;
        int ans=0;
        while(i<nums.size())
        {
            while(j<nums.size() and nums[j]<=right)
            {
                ele.insert(nums[j]);
                j++;                
            }
            while(i<j and i<nums.size())
            {
                auto it=ele.rbegin();
                int val=*it;
                if(val>=left and val<=right)
                {
                    if(nums[i]>=left)
                    {
                        ans++;
                        ans=ans+(j-i-1);
                    }
                    else
                    {
                        ans=ans+(j-i-1);
                    }
                }
                auto itr=ele.find(nums[i]);                
                ele.erase(itr);
                i++;
            }
            i++;
            j=i;
        }
        return ans;
    }
};