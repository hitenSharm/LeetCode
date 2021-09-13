// https://leetcode.com/problems/minimum-cost-for-tickets

class Solution {
    int memo[366];
    int cost[3];
    unordered_map<int,int>ump;
public:
    
   int dp(int i)
    {
        if(i<=0)
            return 0;
        if(memo[i]!=0)
            return memo[i];
        if(ump.find(i)!=ump.end())
        {
            int ans;
            int t1=dp(i-1)+cost[0];
            int t2=dp(i-7)+cost[1];
            int t3=dp(i-30)+cost[2];
            return memo[i]=min(t1,min(t2,t3));            
        }
        return dp(i-1);
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(memo, 0, sizeof(memo)); 
        cost[0]=costs[0];
        cost[1]=costs[1];
        cost[2]=costs[2];
        
        for(int i=0;i<days.size();i++)
        { 
            ump[days[i]]++;
        }
        return dp(days[days.size()-1]);
    }
     
};