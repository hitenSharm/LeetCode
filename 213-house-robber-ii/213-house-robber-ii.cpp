class Solution {
public:
    
//     int recu(vector<int>& dp,vector<int>& nums,int index,int li)
//     {
//         if(index>li)return 0;
//         if(dp[index]!=-1)return dp[index];
        
//         return dp[index]=max(nums[index]+recu(dp,nums,index+2,li),recu(dp,nums,index+1,li));
//     }
    
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        
        //either rob 1-n-1
        //or r0b 0-n-2
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        // recu(dp1,nums,0,nums.size()-2);
        // recu(dp2,nums,1,nums.size()-1);
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        //dp1 is 0->n-2
        for(int i=2;i<=nums.size()-2;i++)
        {
            dp1[i]=max(nums[i]+dp1[i-2],dp1[i-1]);
        }
        //dp2 is 1->n-1
        dp2[1]=nums[1];
        dp2[2]=max(nums[1],nums[2]);
        for(int i=3;i<=nums.size()-1;i++)
        {
            dp2[i]=max(nums[i]+dp2[i-2],dp2[i-1]);
        }
        return max(dp1[nums.size()-2],dp2[nums.size()-1]);
    }
};