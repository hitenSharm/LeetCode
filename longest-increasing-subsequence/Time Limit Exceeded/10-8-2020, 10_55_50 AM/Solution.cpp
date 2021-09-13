// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int memo[10000];
    int recu(vector<int>nums,int i)
    {
        
        if(memo[i]!=-1)
            return memo[i];
        int result=1;
        if(i>=nums.size())
            return 0;
        for(int j=i+1;j<nums.size();j++)
        { 
            if(nums[j]>nums[i])
            { 
                result=max(result,1+recu(nums,j));
            }
        }
        memo[i]=result;
        return result;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        memset(memo,-1,sizeof(memo));
        int result=1;
        for(int i=0;i<nums.size();i++)
        {
             result=max(result,recu(nums,i));
        }
        return result;
    }
};