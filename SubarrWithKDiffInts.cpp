#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

//TODO

class Solution {
public:

	int subArrWithAtmostK(vector<int>& nums,int k)
	{
		if(k==0)
			return 0;
		int n=nums.size();
		unordered_map<int,int>ump;
		int i=0;int j=0;int ans=0;
		while(i<n && j<n)
		{
			while(j<n && ump.size()<=k)
			{
				ump[nums[j]]++;
				if(ump.size()<=k)
					ans+=j-i+1;
				j++;
			}
			while(i<n && i<=j && ump.size()>k)
			{
				ump[nums[i]]--;
				if(ump[nums[i]]==0)
					ump.erase(nums[i]);
				i++;
			}
			ans+=j-i+1;
		}
		return ans;
	}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return (abs(subArrWithAtmostK(nums,k)-subArrWithAtmostK(nums,k-1)));
    }
};