// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>p2=prices;
        sort(prices.begin(), prices.end(), greater<int>());
        int maxi=0;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]-p2[i]>=maxi)
                maxi=prices[i]-p2[i];
        }
        return maxi;
        
    }
};