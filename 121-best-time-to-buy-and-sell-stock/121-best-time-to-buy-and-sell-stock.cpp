class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>suffix(prices.size());
        suffix[prices.size()-1]=prices[prices.size()-1];
        int minTillHere=INT_MAX;
        for(int i=prices.size()-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],prices[i]);            
        }
        int ans=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            minTillHere=min(minTillHere,prices[i]);
            ans=max(ans,suffix[i+1]-minTillHere);
        }
        return ans;
    }
};