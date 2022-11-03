class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        long t=target;
        for(int i=0;i<nums.size();)
        {
            for(int j=i+1;j<nums.size();)
            {
                long long s=t-(nums[i]+nums[j]);
                int l=j+1;
                int r=nums.size()-1;
                while(l<r)
                {
                    if(nums[l]+nums[r]==s)
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int ele=nums[l];
                        while(l<r and ele==nums[l])l++;
                        ele=nums[r];
                        while(l<r and ele==nums[r])r--;
                    }
                    else if(nums[l]+nums[r]<s){
                        l++;
                    }
                    else
                        r--;
                }
                int ele=nums[j];
                while(j<nums.size() and ele==nums[j])j++;
            }
            int ele=nums[i];
            while(i<nums.size() and ele==nums[i])i++;
        }
        return ans;
    }
};