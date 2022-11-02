class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //o(n)   and o(1) concept is by using linked list concept
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};