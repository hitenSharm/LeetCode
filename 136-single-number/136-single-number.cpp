class Solution {
public:
    int singleNumber(vector<int>& nums) {        
        int ele=nums[0];
        for(int i=1;i<nums.size();i++)ele=ele^nums[i];
        return ele;
    }
};