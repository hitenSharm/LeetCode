class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        long tag=target;
        for(int i=0;i<nums.size();i++)
        {
            if(i-1>=0 and nums[i]==nums[i-1])continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]==nums[j-1] and (j-1)!=i)continue;
                int l=j+1,r=nums.size()-1;
                long t=tag-(nums[i]+nums[j]);
                while(l<r)
                {
                    if(nums[l]+nums[r]<t)
                        l++;
                    else if(nums[l]+nums[r]>t)
                        r--;
                    else
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int curr=nums[l];
                        while(l<r and nums[l]==curr)
                            l++;
                        curr=nums[r];
                        while(l<r and nums[r]==curr)
                            r--;
                    }
                }
            }
        }
        return ans;
    }
};