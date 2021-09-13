// https://leetcode.com/problems/coin-change

class Solution {
public:
    
    int recu(vector<int>& dp,vector<int>& coins,int amt)
    {
        //cout<<amt<<" amt \n";        
        if(amt<0)
            return -1;        
        if(amt==0)
        {
            return 0;
        }
        if(dp[amt]!=-2)
        {            
            return dp[amt];
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int x=recu(dp,coins,amt-coins[i]);                        
            if(x>=0)
            {                
                mini=min(mini,1+x);
            }
            
            
        }
       
        if(mini==INT_MAX)
            dp[amt]=-1;
        else
            dp[amt]=mini;
        return dp[amt];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)
            return 0;
        vector<int>dp(amount+1,-2);
        return recu(dp,coins,amount);
    }
};