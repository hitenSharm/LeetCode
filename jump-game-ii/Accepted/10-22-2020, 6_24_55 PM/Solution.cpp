// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    
    int jump(vector<int>& nums) {
      int siz=nums.size();
      int ans=0;
        int pos=0,des=0;
      for(int i=0;i<siz-1;i++)
      { 
        des=max(des,i+nums[i]);
          if(pos==i)
          { 
            pos=des;
              ans++;
          }
      }
        return ans;
    }
};