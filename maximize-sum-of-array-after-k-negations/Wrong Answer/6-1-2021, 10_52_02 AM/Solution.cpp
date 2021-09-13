// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations

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
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int negs=0;int sumNegs=0;int sumPos=0;
        for(int i=0;i<nums.size();i++)
        {
          if(nums[i]<=0)
          {
            negs++;
            sumNegs+=nums[i];
          }
          else
            sumPos+=nums[i];
        }
        while(k>negs and k>=2)
        {
          if(sumPos<abs(sumNegs))
          {             
            if(k-2>negs)
            {              
              k=k-2;
              continue;
            }
            else
              break;
          }
          else
          { 
            k=k-2;
          }
        }  
        
        int tempSum=0;
        for(int i=0;i<k;i++)
        {
           if(nums[i]<0)
            tempSum=tempSum+abs(nums[i]);
          else
            tempSum=tempSum-nums[i];
        } 
        sumNegs=sumNegs+(2*tempSum);
        return sumNegs+sumPos;
    }
};

