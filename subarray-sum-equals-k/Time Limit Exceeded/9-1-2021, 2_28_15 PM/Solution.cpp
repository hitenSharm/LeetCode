// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int s=0;
            for(int j=i;j<nums.size();j++)
            {
                s+=nums[j];
                if(s==k)cnt++;
            }
        }
        return cnt;
    }
};