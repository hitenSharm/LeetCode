class Solution {
public:
    vector<vector<int>>dp;
    int recu(vector<int>& p,int index,int& fee,int bs)
    {
        if(index>=p.size())return 0;//base case //no buy or sell
        if(dp[index][bs]!=-1)return dp[index][bs];
        if(bs==1)//can buy
        {
            //either buy or dont buy
            int buying=recu(p,index+1,fee,0)-p[index];
            int notBuy=recu(p,index+1,fee,1);//
            return dp[index][bs]=max(buying,notBuy);
        }
        else
        {
            //need to sell
            int sell=recu(p,index+1,fee,1)+p[index]-fee;
            int noSell=recu(p,index+1,fee,0);
            return dp[index][bs]=max(sell,noSell);
        }
        return -1;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return recu(prices,0,fee,1);//1 means i can buy
    }
};