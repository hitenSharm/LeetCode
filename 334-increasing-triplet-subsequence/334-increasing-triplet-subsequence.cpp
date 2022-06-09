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
    bool increasingTriplet(vector<int>& nums) {
        vector<int>leftMin(nums.size(),INT_MAX);
		vector<int>rightMax(nums.size(),INT_MIN);
		for(int i=0;i<nums.size();i++)
		{
			(i==0 ? leftMin[i]=nums[i] : leftMin[i]=min(leftMin[i-1],nums[i]));
		}
		for(int i=nums.size()-1;i>=0;i--)
		{
			(i==nums.size()-1 ? rightMax[i]=nums[i] : rightMax[i]=max(rightMax[i+1],nums[i]));
		}
		for(int i=0;i<nums.size();i++)
		{
			if(leftMin[i]<nums[i] and rightMax[i]>nums[i])return true;
			//this would mean that at nums[i] there is a value on  its left which is smaller than current
			//and on right that is larger than current
		}
		return false;
    }
};