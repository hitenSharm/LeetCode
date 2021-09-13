// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
       vector<int>ref=nums;
       int cnt[3]={0};
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        for(int i=1;i<3;i++)
        {
            cnt[i]=cnt[i-1]+cnt[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[cnt[ref[i]]-1]=ref[i];
            cnt[ref[i]]--;
        }        
    }
};