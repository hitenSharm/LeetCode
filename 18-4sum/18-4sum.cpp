class Solution {
public:    

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            long long int t1=target-nums[i];
            for(int j=i+1;j<nums.size();j++)
            {                
                long long int finding=t1-nums[j];
                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    if(nums[l]+nums[r]<finding)l++;
                    else if(nums[l]+nums[r]>finding)r--;
                    else
                    {
                        vector<int>temp{nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(temp);
                        int q3=nums[l],q4=nums[r];
                        while(r>l and nums[r]==q4)r--;
                        while(l<r and nums[l]==q3)l++;
                    }
                }
                while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};