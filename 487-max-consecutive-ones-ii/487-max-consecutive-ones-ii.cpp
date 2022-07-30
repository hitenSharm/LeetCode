class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int zCnt=0;
        int i=0,j=0;
        int ans=INT_MIN;
        while(i<nums.size())
        {
            while(j<nums.size() and (zCnt<1 || (zCnt==1 and nums[j]!=0)))
            {
                if(nums[j]==0)zCnt++;                
                j++;
            }
            ans=max(ans,j-i);
            if(nums[i]==0)zCnt--;
            i++;
        }
        return ans;
    }
};