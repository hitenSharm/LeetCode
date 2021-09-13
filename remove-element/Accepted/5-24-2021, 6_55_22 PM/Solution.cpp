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
    	vector<int> index;
        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]==val)
        		index.push_back(i);
        }
        int rem=0;
        for(int i=0;i<index.size();i++)
        {
        	nums.erase(nums.begin()+index[i]-rem);
        	rem++;
        }
        return nums.size();
    }
};