class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //o(n)   and o(1) concept is by using linked list concept
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];//move twice
        }while(slow!=fast);
        fast=nums[0];//head
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};