// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]++;
        }
        int maxi=0;
        int indi;
        for(auto a:ump)
        {
         
            if(a.second>maxi)
            {
                maxi=a.second;
                indi=a.first;
            }
          
        }
        return indi;
    }
};