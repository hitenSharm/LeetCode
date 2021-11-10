class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int ops=0;
        int st=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[st])continue;            
            ops+=i;
            st=i;            
        }
        return ops;
    }
};