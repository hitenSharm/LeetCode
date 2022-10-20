class Solution {
public:
        
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1)return true;
        //dp approach, at each point i can jump for the next jump[i] indexes
        //i just need to know if i can reach end
        //greedy approach is to see how max far i can jump when moving to 
        //the max possible index = i+nums[i] where i is in prev range
        int maxIndex=nums[0];
        for(int i=1;i<=maxIndex;i++)
        {
            if(i>=nums.size()-1)return true;
            maxIndex=max(maxIndex,i+nums[i]);
        }
        return false;
    }
};