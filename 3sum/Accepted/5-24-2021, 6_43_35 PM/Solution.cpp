// https://leetcode.com/problems/3sum

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {     	
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
     				ans.push_back(temp);     					    			
     					while(left<right and nums[left]==nums[left+1])
     						left++;
     					while(left<right and nums[right]==nums[right-1])
     						right--;
     					left++;
     					right--;
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