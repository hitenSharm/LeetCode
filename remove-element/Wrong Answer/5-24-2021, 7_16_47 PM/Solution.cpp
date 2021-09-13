// https://leetcode.com/problems/remove-element

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
    int removeElement(vector<int>& nums, int val) {
    	int i=0;
    	int n=nums.size();
    	while(i<nums.size())
    	{
    		if(nums[i]==val)
    		{
    			nums[i]=nums[n-1];
    			n--;
    		}
            else
    		i++;
    	}
    	return n;
    }
};