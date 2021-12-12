class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currEle=nums[0];
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==currEle)cnt++;
            else
            {
                cnt--;
                if(cnt==0 and i+1<nums.size())currEle=nums[i+1];
            }
        }
        return currEle;
    }
};