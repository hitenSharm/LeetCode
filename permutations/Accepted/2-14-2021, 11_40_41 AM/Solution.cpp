// https://leetcode.com/problems/permutations

class Solution {
public:
    
    void backTrack(vector<vector<int>> &ans, vector<int>&temp,vector<int>&nums,int size,unordered_map<int,int>ump){
        if(size>=nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(ump[nums[i]]==0)
            {
                temp.push_back(nums[i]);
                ump[nums[i]]=1;
                backTrack(ans,temp,nums,size+1,ump);
                temp.pop_back();
                ump[nums[i]]=0;
            }
            
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]=0;
        }
        backTrack(ans,temp,nums,0,ump);
        return ans;
    }
};