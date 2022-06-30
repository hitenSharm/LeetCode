class Solution {
public:
    
    vector<int>vis;
    
    int recu(vector<int>& nums,int i,unordered_map<int,int>& ump,vector<int>& dp)
    {        
        if(dp[i]!=-1)return dp[i];
        int ans=0;
        vis[ump[nums[i]]]=1;
        if(ump.find(nums[i]+1)!=ump.end() and vis[ump[nums[i]+1]]==0)
        {            
            ans=ans+1+recu(nums,ump[nums[i]+1],ump,dp);
        }
        if(ump.find(nums[i]-1)!=ump.end() and vis[ump[nums[i]-1]]==0)
        {            
            ans=ans+1+recu(nums,ump[nums[i]-1],ump,dp);
        }
        return dp[i]=ans;
    }

    int longestConsecutive(vector<int>& nums) {
        vis.resize(nums.size(),0);
        vector<int>dp(nums.size(),-1);
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++)ump[nums[i]]=i;
        int ans=0;        
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,1+recu(nums,i,ump,dp));            
        }
        return ans;
    }
};