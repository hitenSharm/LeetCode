// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>vis;
        for(int i=0;i<nums.size();i++)
        {            
            for(int j=i;j<nums.size();j++)
            {
                vector<int>temp;
                for(int k=i;k<=j;k++)
                    temp.push_back(nums[k]);
                if(vis.find(temp)==vis.end())
                {
                    vis.insert(temp);
                    ans.push_back(temp);
                }
            }            
        }
        ans.push_back({});
        return ans;
    }
};