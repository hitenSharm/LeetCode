// https://leetcode.com/problems/target-sum

class Solution {
public:
    int cnt=0;
    void recu(vector<int>& nums,int s,int i,int& t)
    {
        if(i==nums.size())
        {
            if(s==t)cnt++;
            return ;
        }
        recu(nums,s+nums[i],i+1,t);
        recu(nums,s-nums[i],i+1,t);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        recu(nums,0,0,target);
        return cnt;
    }
};