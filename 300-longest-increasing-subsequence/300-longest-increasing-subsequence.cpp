class Solution {
public:
    vector<vector<int>>dp;
    int recu(vector<int>& nums, int prev, int index)
    {
        if (index >= nums.size())return 0;
        if (dp[prev + 1][index] != -1)return dp[prev + 1][index];

        int ans = recu(nums, prev, index + 1);//dont take that index or cant take that index        
        if (prev == -1 || nums[index] > nums[prev])
            ans = max(ans, 1 + recu(nums, index, index + 1));
        return dp[prev+1][index]=ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size()+1, vector<int>(nums.size(), -1));
        return recu(nums, -1, 0);
    }
};