class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //at each point we can either buy or sell
        // so we can have 2 arrays biy & sell
        //if i wanna sell at i
        //sel[i] = max of either i dont sell(sell[i-1]) or the max i 
        //profit by buying till that moment + p[i] => b[i-1] + p[i]
        
        //calc b[i] = max of eithher no buy => b[i-1] or i must have sold something to buy again, (no buy buy    option,invalid) => sell[i-2] - p[i] as sell is on cool down
        
        vector<int>buy(prices.size(),0);
        vector<int>sell(prices.size(),0);
        
        buy[0]=-prices[0];
        for(int i=1;i<prices.size();i++)
        {
            if(i-2<0)buy[i]=max(-prices[i],buy[i-1]);
            else
            buy[i]=max(sell[i-2]-prices[i],buy[i-1]);
            
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
        }
        return max(buy[prices.size()-1],sell[prices.size()-1]);
    }
};