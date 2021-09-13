// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>p2=prices;
        if(p2.size()==0)
            return 0;
        int mini=p2[0];
        int max_diff=0;
        
        for(int i=1;i<p2.size();i++)
        {
            if(p2[i]<mini)
            {
                mini=p2[i];
                i++;
            }
            else{
            int td=p2[i]-mini;
            max_diff=max(max_diff,td);
            }
        }
        
        return max_diff;
    }
};