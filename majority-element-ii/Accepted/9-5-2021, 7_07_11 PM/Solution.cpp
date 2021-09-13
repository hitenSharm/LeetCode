// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans; 
        int c1=0,c2=0;
        int m1=0,m2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m1==nums[i])
                c1++;
            else if(m2==nums[i])
                c2++;
            else if(c1==0)
            {
                m1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                c2=1;
                m2=nums[i];
            }
            else
            {
                c1--;
                c2--;
            }
        }     
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==m1)c1++;
            if(nums[i]==m2)c2++;
        }
        if(m1==m2)c2=0;
        if(c1>(nums.size()/3))
            ans.push_back(m1);
        if(c2>(nums.size()/3))
            ans.push_back(m2);
        return ans;
    }
};