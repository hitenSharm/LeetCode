// https://leetcode.com/problems/heaters

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxRadi=0;
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        vector<int>ans(houses.size(),INT_MAX);
        
        int i=0;
        int j=0;
        
        for(;i<houses.size() && j<heaters.size();)
        {
            if(houses[i]<=heaters[j])
            {
                ans[i]=abs(heaters[j]-houses[i]);
                i++;
            }
            else
            {
                j++;
            }
        }
        i=houses.size()-1;
        j=heaters.size()-1;
        for(;i>=0 && j>=0;)
        {
            if(houses[i]>=heaters[j])
            {
                ans[i]=min(ans[i],abs(heaters[j]-houses[i]));
                i--;
            }
            else
            {
                j--;
            }
        }
        return *max_element(ans.begin(), ans.end());
        
    }
};