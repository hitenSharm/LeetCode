// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s=0;
        unordered_map<int,int>ump;
        int cnt=0;
        ump[s]++;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            cnt+=ump[s-k];
            ump[s]++;
        }
        return cnt;
    }
};