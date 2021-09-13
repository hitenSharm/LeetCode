// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    
    void recu(set<vector<int>>& vis,vector<vector<int>>& ans,vector<int>& temp,vector<int>& nums,int i)
    {
        if(i>=nums.size())return ;
        temp.push_back(nums[i]);
        if(vis.find(temp)==vis.end())
        {
            vis.insert(temp);
            ans.push_back(temp);
        }
        recu(vis,ans,temp,nums,i+1);
        temp.pop_back();
        recu(vis,ans,temp,nums,i+1);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>>vis;
        vector<int>temp;
        recu(vis,ans,temp,nums,0);
        ans.push_back({});
        return ans;
    }
};