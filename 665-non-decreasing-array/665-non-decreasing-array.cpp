class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                //invalid case
                cnt++;
                //prev==curr is favourable
                if ((i - 2 >= 0 and nums[i - 2] <= nums[i]) || i == 1)
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
            }
        }
        return cnt <= 1;
    }
};