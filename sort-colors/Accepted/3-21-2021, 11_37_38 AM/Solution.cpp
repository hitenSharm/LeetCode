// https://leetcode.com/problems/sort-colors

class Solution {
public:
    void sortColors(vector<int>& nums) {       
       int cnt[3]={0};
        for(int i=0;i<nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(cnt[0]>0)
            {
                nums[i]=0;
                cnt[0]--;
                continue;
            }
            if(cnt[1]>0)
            {
                nums[i]=1;
                cnt[1]--;
                continue;
            }
            if(cnt[2]>0)
            {
                nums[i]=2;
                cnt[2]--;
                continue;
            }
        }
               
    }
};