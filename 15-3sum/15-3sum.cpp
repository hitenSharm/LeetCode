class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()==0)return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();)
        {
            int t1=nums[i];
            //2sum
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                if(nums[j]+nums[k]+t1==0)
                {
                    ans.push_back({nums[j],nums[k],t1});
                    j++;
                    k--;
                    while(j<k and nums[j]==nums[j-1])j++;
                    while(j<k and nums[k]==nums[k+1])k--;
                }
                else if(nums[j]+nums[k]+t1<0)j++;
                else
                    k--;
            }
            while(i<nums.size() and nums[i]==t1)i++;
        }
        return ans;
    }
};