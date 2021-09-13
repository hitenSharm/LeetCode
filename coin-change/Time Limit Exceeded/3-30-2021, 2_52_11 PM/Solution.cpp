// https://leetcode.com/problems/coin-change

class Solution {
public:
    
    int recu(vector<int>& dp,vector<int>& coins,int amt)
    {
        //cout<<amt<<" amt \n";        
        if(amt<0)
            return INT_MIN+1;
        if(dp[amt]!=-1)
            return dp[amt];
        if(amt==0)
        {
            
            return 0;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int x=recu(dp,coins,amt-coins[i]);                        
            if(x>=0)
            {
                int temp=1+x;
                mini=min(mini,temp);
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
        vector<int>dp(amount+1,-1);
        return dp[amount]=recu(dp,coins,amount);
    }
};