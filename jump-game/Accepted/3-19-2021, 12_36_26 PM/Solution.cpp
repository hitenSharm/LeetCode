// https://leetcode.com/problems/jump-game

class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        if(nums.size()==1||nums.size()==0)
            return true;
        int curr=0;
        int maxFromHere=0;
        maxFromHere=curr+nums[curr];
        curr++;
        while(curr<=maxFromHere)
        {
            maxFromHere=max(curr+nums[curr],maxFromHere);
            if(maxFromHere>=nums.size())
                return true;
            curr++;
        }
        if(maxFromHere<nums.size()-1)
            return false;
        return true;
    }
};