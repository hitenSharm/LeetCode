class Solution {
public:
    
    int recu(vector<int>& dp,unordered_map<int,int>& ump,int element)
    {        
        int index=ump[element];
        if(dp[index]!=-1)return dp[index];
        int ans=1;
        if(ump.find(element+1)!=ump.end())
        {
            ans+=recu(dp,ump,element+1);
        }
        //this way i am just going fwd and if that element has explored all possobo=iliteis ahead of itself
        //i can return it
        return dp[index]=ans;
    }
    
    int longestConsecutive(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        unordered_map<int,int>ump;
        
        for(int i=0;i<nums.size();i++)ump[nums[i]]=i;
        
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,recu(dp,ump,nums[i]));
        }
        return ans;   
    }
};