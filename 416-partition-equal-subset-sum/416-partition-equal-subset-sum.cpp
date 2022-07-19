class Solution {
public:
    vector<vector<int>>dp;
    int ts=0;
    bool recu(vector<int>& nums,int s1,int s2,int index)
    {
        if(index>=nums.size())
        {
            if(s1==s2)return true;
            return false;
        }
        if(dp[s1][index]!=-1)return (dp[s1][index] == 0 ? true : false);
        if(dp[s2][index]!=-1)return (dp[s2][index] == 0 ? true : false);
        bool ans=(recu(nums,s1+nums[index],s2,index+1) || recu(nums,s1,s2+nums[index],index+1));
        dp[s1][index]=dp[s2][index]=(ans ? 0 : 1);
        return ans;
    }
    
    bool canPartition(vector<int>& nums) {        
        int s=accumulate(nums.begin(),nums.end(),0);
        ts=s;
        dp.resize(s,vector<int>(nums.size(),-1));
        return recu(nums,0,0,0);
    }
};