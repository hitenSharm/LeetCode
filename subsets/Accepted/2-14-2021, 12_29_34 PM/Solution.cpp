// https://leetcode.com/problems/subsets

class Solution {
public:
    
    void backTrack(vector<vector<int>>&ans,vector<int>&temp,vector<int>&nums,int siz,int curr)
    {
        if(curr==siz)
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=curr;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            backTrack(ans,temp,nums,siz,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;        
        for(int i=0;i<=nums.size();i++)
        {
            backTrack(ans,temp,nums,i,0);
        }
        return ans;
    }
};