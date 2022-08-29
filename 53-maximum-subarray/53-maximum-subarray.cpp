class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxAns=INT_MIN;        
        int s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            maxAns=max(maxAns,s);
            if(s<0)s=0;
        }
        //if(maxAns<0)maxAns=0;
        return maxAns;
    }
};