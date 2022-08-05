class Solution {
public:
    vector<vector<int>>dp;
    int recu(int amt,vector<int>& c,int index)
    {
        if(amt==0)return 1;
        if(index>=c.size() || amt<0)return 0;        
        if(dp[amt][index]!=-1)return dp[amt][index];
        
        return dp[amt][index]=recu(amt-c[index],c,index)+recu(amt,c,index+1);
    }
    
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+1,vector<int>(coins.size(),-1));
        return recu(amount,coins,0);
    }
};