// https://leetcode.com/problems/3sum-closest

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

    int twoSumClosest(vector<int>& nums, int target,int s)
    {
        int l=s,r=nums.size()-1;
        int sumClosest=10000;
        while(l<r)
        {
            int tempSum=nums[l]+nums[r];
            if(tempSum==target)return tempSum;            
            if(abs(tempSum-target)<abs(sumClosest-target))
            {
                sumClosest=tempSum;
            }
            if(tempSum<target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return sumClosest;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        int sumClosest=10000;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int sumTwo=twoSumClosest(nums,target-nums[i],i+1);            
            int tempSum=sumTwo+nums[i];
            if(abs(tempSum-target)<abs(sumClosest-target))
            {
                sumClosest=tempSum;
            }
            if(tempSum==target)return tempSum;
        }
        return sumClosest;
    }
};