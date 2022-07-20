class Solution {
public:

    vector<vector<int>>dp;

    int recu(vector<int>& prices,int bs,int index)
    {
        if(index>=prices.size())return 0;        
        int ans=0;
        if(dp[index][bs]!=-1)return dp[index][bs];
        if(bs==0)
        {
            //can buy
            int t1=recu(prices,bs,index+1);
            int t2=recu(prices,1,index+1) - prices[index];
            ans = max(t1,t2);
        }
        else
        {
            //can sell
            int t1=recu(prices,bs,index+1);
            int t2=recu(prices,0,index+2) + prices[index];
            ans = max(t1,t2);
        }
        return dp[index][bs]=ans;
    }

    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return recu(prices,0,0);
    }
};