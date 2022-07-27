class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadandes
        int maxTillHere=0;
        int maxSoFar=0;
        int neg=INT_MIN;
        int negCnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)negCnt++;
            neg=max(neg,nums[i]);
            maxTillHere+=nums[i];
            maxSoFar=max(maxSoFar,maxTillHere);
            if(maxTillHere<0)maxTillHere=0;
        }
        if(negCnt==nums.size())return neg;
        
        return maxSoFar;
    }
};