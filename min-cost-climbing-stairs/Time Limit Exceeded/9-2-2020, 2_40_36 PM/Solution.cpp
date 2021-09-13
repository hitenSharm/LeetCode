// https://leetcode.com/problems/min-cost-climbing-stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int>a=cost;
        int n=cost.size();
        int t=0;
        for(int i=0;i<n;i++){ 
            if(cost[i]==0)
                t++;
            
        }
        if(t==n)
            return 0;
        
        if(n==0)
            return 0;
        if(n==1)
            return cost[0];
        if(n==2)
            return min(a[0],a[1]);
        
        for(int i=2;i<n;){ 
          a[i]=min(a[i-1],a[i-2])+cost[i];
            
        }
        return min(a[n-1],a[n-2]);
    }
};