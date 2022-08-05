class Solution {
public:
    int dp[2501][2501];
    // int recu(vector<int>& nums,int prev,int index)
    // {
    //     if(index>=nums.size())return 0;
    //     int ans=recu(nums,prev,index+1);//no take or cant take
    //     if(prev==-1 || nums[index]>nums[prev])
    //         ans=max(ans,1+recu(nums,index,index+1)); //if can take
    //     return ans;
    // }
    
    int recu(vector<int>& nums,int prev,int index)
    {
        if(index>=nums.size())return 0;
        if(dp[prev+1][index]!=-1)return dp[prev+1][index];
        
        int ans=recu(nums,prev,index+1);//no take or cant take        
        if(prev==-1 || nums[index]>nums[prev])
            ans=max(ans,1+recu(nums,index,index+1)); //if can take
        return dp[prev+1][index]=ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        //do in form of prev index and current index
        //if i take an element then i update the prev index for the new recu
        //else i let my prev index be same and move fwd
        memset(dp,-1,sizeof(dp));
        return recu(nums,-1,0);
    }
};