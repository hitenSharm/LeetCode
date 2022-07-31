class Solution {
public:
    vector<vector<int>>dp;
    // int recu(vector<int>& p,int index,int& fee,int bs)
    // {
    //     if(index>=p.size())return 0;//base case //no buy or sell
    //     if(dp[index][bs]!=-1)return dp[index][bs];
    //     if(bs==1)//can buy
    //     {
    //         //either buy or dont buy
    //         int buying=recu(p,index+1,fee,0)-p[index];
    //         int notBuy=recu(p,index+1,fee,1);//
    //         return dp[index][bs]=max(buying,notBuy);
    //     }
    //     else
    //     {
    //         //need to sell
    //         int sell=recu(p,index+1,fee,1)+p[index]-fee;
    //         int noSell=recu(p,index+1,fee,0);
    //         return dp[index][bs]=max(sell,noSell);
    //     }
    //     return -1;
    // }
    
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,0));
        //1 is buy
        dp[0][1]=-prices[0];
        dp[0][0]=0;//0 means i didnt buy
        for(int i=1;i<prices.size();i++)
        {
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
            dp[i][0]=max(dp[i-1][1]+prices[i]-fee,dp[i-1][0]);
        }
        return max(dp[prices.size()-1][0],dp[prices.size()-1][1]);
    }
};