class Solution {
public:
    vector<int>dp;
    int recu(unordered_map<int,int>& ump,int i,vector<int>& nums)
    {
        if(dp[i]!=-1)return dp[i];
        int ele=nums[i];
        if(ump.find(ele+1)!=ump.end())
        {
            return dp[i]=1+recu(ump,ump[ele+1],nums);
        }
        return dp[i]=1;
    }
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>ump;
        dp.resize(nums.size(),-1);
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]=i;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,recu(ump,i,nums));
        }
        return ans;
    }
};