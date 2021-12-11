class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>prefix(prices.size(),0);
        vector<int>suffix(prices.size(),0);
        prefix[0]=prices[0];
        suffix[prices.size()-1]=prices[prices.size()-1];
        
        for(int i=1;i<prices.size();i++)
        {
            prefix[i]=min(prices[i],prefix[i-1]);
        }
        
        for(int i=prices.size()-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],prices[i]);
        }
        int ans=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            ans=max(ans,suffix[i+1]-prefix[i]);
        }
        return ans;
    }
};