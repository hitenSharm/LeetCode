class Solution {
public:
    
    vector<int>dp;
    
    int recu(int amt,vector<int>& c)
    {
        if(amt==0)return 0;
        if(amt<0)return -1;        
        int ans=INT_MAX;
        if(dp[amt]!=-2)return dp[amt];
        for(int i=0;i<c.size();i++)
        {
            int temp=recu(amt-c[i],c);
            if(temp!=-1)ans=min(ans,1+temp);
        }
        if(ans==INT_MAX)ans=-1;
        return dp[amt]=ans;
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-2);
        
        return recu(amount,coins);
        
    }
};