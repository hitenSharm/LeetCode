class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int t1=nums[0]*nums[1]*nums[2];
        t1=max(t1,nums[0]*nums[1]*nums[n]);
        t1=max(t1,nums[0]*nums[n]*nums[n-1]);
        t1=max(t1,nums[n]*nums[n-1]*nums[n-2]);
        return t1;
    }
};