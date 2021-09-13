// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    
    bool makeSum(vector<int>&memo ,vector<int>& nums, int sum,int index,int tsum)
    {
        if(sum==0)
            return 1;
        if(sum<0 || index>=nums.size() || (sum>0) && index>=nums.size())
            return 0;
        
        if(memo[sum]!=-1)
            return memo[sum];
        
        return memo[tsum-sum]= memo[sum] = max(makeSum(memo,nums,sum-nums[index],index+1,tsum),makeSum(memo,nums,sum,index+1,tsum));
        
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2!=0)
            return false;
        vector<int>memo(sum+1,-1);
        return makeSum(memo,nums,sum/2,0,sum)==1 ? true : false;    
    }
};