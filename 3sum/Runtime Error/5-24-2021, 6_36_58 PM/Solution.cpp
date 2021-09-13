// https://leetcode.com/problems/3sum

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
     	map<vector<int>,int>present;
     	sort(nums.begin(),nums.end());
     	int n=nums.size();
        int target=0;
     	vector<vector<int>>ans;
     	for(int i=0;i<n;i++)   
     	{
     		if(i>0 && nums[i]==nums[i-1])continue;
     		int left=i+1;
    		int right=n-1;
    		while(left<right)
     		{
     			int sum=nums[i]+nums[left]+nums[right];
     			if(sum==target){
     				vector<int> temp={nums[i],nums[left],nums[right]};
     				if(present.find(temp)!=present.end())
     					continue;
     				else
     				{
     					ans.push_back(temp);
     					present[temp]=1;
     					int lval=nums[left];
     					int rval=nums[right];
     					while(lval<n and lval==nums[left])
     						left++;
     					while(rval>=0 and rval==nums[right])
     						right--;
     				}
     			}
     			if(sum<target)
     				left++;
     			if(sum>target)
     				right--;
     		}
     	}
     	return ans;
    }
};