// https://leetcode.com/problems/4sum

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

//using map of vector of pairs

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int,vector<pair<int,int>>>ump;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        	for(int j=i+1;j<n;j++)
        		ump[nums[i]+nums[j]].push_back(make_pair(i,j));

        vector<vector<int>>ans;
        map<vector<int>,int>present;
        for(int i=0;i<n;i++)
		{
			if(i>0 && nums[i]==nums[i-1])continue;
			for(int j=i+1;j<n;j++)
			{
				if(j>i+1 && nums[j]==nums[j-1])continue;
				int sum=nums[i]+nums[j];

				if(ump.find(sum)!=ump.end())
				{
					for(auto it:ump[sum])
					{
						int k=it.first;
						int l=it.second;
						if(k>j)
						{
							vector<int>temp ={nums[i],nums[j],nums[k],nums[l]};
							if(present.find(temp)!=present.end())
								continue;
							else
							{
								ans.push_back(temp);
								present[temp]=1;
							}								
						}
					}
				}
			}
		}        	
		return ans;

    }
};