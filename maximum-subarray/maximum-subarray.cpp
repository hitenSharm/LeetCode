class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar=INT_MIN,maxi=0;        
        for(int i=0;i<nums.size();i++)
        {
            maxi+=nums[i];
            if(maxi<0){
                maxi=0;
                maxSoFar=max(maxSoFar,nums[i]);    
                continue;
            }
            maxSoFar=max(maxSoFar,maxi);
        }
        return maxSoFar;
    }
};