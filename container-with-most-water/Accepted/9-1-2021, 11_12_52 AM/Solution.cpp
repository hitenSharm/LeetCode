// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<pair<int,int>>p;
        for(int i=0;i<height.size();i++)
        {
            p.push_back({height[i],i});
        }
        sort(p.begin(),p.end());
        vector<int>prefix(p.size());
        vector<int>suffix(p.size());
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=p.size()-1;i>=0;i--)
        {
            maxi=max(maxi,p[i].second);
            mini=min(mini,p[i].second);
            prefix[i]=mini;
            suffix[i]=maxi;
        }
        int ans=0;
        for(int i=0;i<p.size()-1;i++)
        {
            ans=max(ans,p[i].first*(abs(p[i].second-suffix[i+1])));
            ans=max(ans,p[i].first*(abs(p[i].second-prefix[i+1])));
        }
        return ans;
    }
};