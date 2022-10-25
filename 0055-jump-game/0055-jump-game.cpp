class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxiIndex=nums[0];
        for(int i=0;i<=maxiIndex;i++)
        {
            if(i>=nums.size()-1)return true;
            maxiIndex=max(maxiIndex,nums[i]+i);
        }
        return false;
    }
};

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();