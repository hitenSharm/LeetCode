class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //the 2 most frequent elements should must be the POSSIBLE answers as
        //together they form more than half the array        
        int ele1=0;
        int ele2=0;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
            {
                cnt1++;
            }
            else if(nums[i]==ele2)
            {
                cnt2++;
            }
            else if(cnt1==0)
            {
                ele1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                ele2=nums[i];
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;                
            }
        }
        int c1=0,c2=0;
        for(auto i:nums){
            if(i==ele1)c1++;
            if(i==ele2)c2++;
        }
        vector<int>ans;
        if(c1>((nums.size())/3))ans.push_back(ele1);
        if(c2>((nums.size())/3) and ele1!=ele2)ans.push_back(ele2);
        return ans;
    }
};