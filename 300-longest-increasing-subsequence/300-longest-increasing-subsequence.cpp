class Solution {
public:
    //vector<vector<int>>dp;
    //     int recu(vector<int>& nums, int prev, int index)
    //     {
    //         if (index >= nums.size())return 0;
    //         if (dp[prev + 1][index] != -1)return dp[prev + 1][index];

    //         int ans = recu(nums, prev, index + 1);//dont take that index or cant take that index        
    //         if (prev == -1 || nums[index] > nums[prev])
    //             ans = max(ans, 1 + recu(nums, index, index + 1));
    //         return dp[prev+1][index]=ans;
    //     }

    int lengthOfLIS(vector<int>& nums) {
        vector<int>lis(nums.size(), 0);

        lis[0] = 1;//lis till that index

        for (int i = 1; i < nums.size(); i++)
        {
            lis[i]=1;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] and lis[i] < lis[j] + 1)
                    lis[i] = lis[j] + 1;
            }
        }
        return *max_element(lis.begin(),lis.end());
        //do nlog n
    }
};