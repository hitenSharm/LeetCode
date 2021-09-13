// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    
    int jump(vector<int>& nums) {
      int siz=nums.size();
      int curr=0;
       int currTill;
      // int currMax;
      int jumps=0;
      for(int i=0;i<siz;)
      {
        int maxPosi=nums[curr];
        jumps++;
        currTill=i+maxPosi;
        if(currTill>siz)
        break;
        int temp=currTill;
        for(int j=curr+1;j<currTill;j++)
        {
          if(j<siz)
          if(nums[j]+nums[curr]>nums[curr]+nums[temp])
          temp=j;
        }
        currTill=temp;
        i=currTill;
        curr=currTill;
      }  
      return jumps;  
    }
};