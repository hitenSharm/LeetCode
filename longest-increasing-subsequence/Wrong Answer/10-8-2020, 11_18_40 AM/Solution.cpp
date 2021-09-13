// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int lis[nums.size()];
        for(int i=0;i<nums.size();i++)
            lis[i]=1;
        for(int i=0;i<nums.size();i++)
           for(int j=i+1;j<nums.size();j++)
           { 
                if(j>nums.size())
                    break;
                if(nums[j]>nums[i]&&lis[i]+1>lis[j])
                {
                   lis[j]=lis[i]+1;
                }
           }
        int mx=1;
        for(int i=0;i<nums.size();i++)
            mx=max(mx,lis[i]);
        return mx;
    }
};