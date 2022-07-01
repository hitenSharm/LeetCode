class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int ans=nums[0];
       int maxEnding=nums[0],minEnding=nums[0];       
       for(int i=1;i<nums.size();++i)
       {
           int temp=maxEnding;
           maxEnding=max(nums[i],max(maxEnding*nums[i],minEnding*nums[i]));
           //if we start from curr element ie nums[i], if nums is neg, we should take min neg if it is also less than 0, if positive we shud take max
           //similarly for min
           minEnding=min(nums[i],min(temp*nums[i],minEnding*nums[i]));
           ans=max(ans,maxEnding);
       }
       return ans;
    }
};