class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        int ans = 0;
        int len = 0;
        for (auto i : nums)
        {
            if (i == maxi)len++;
            else
            {
                ans = max(ans, len);
                len = 0;
            }
        }
        ans=max(ans,len);
        return ans;
    }
};