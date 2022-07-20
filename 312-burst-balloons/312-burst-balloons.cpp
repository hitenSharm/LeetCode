class Solution {
public:
    vector<vector<int>>dp;
    int lastGuy(int i,int j,vector<int>& nums)
    {
        if(i>j)return 0;
        int ans=0;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++)
        {
            //i assume that this is the last guy i burst =>i can take the ends of the array for multiplication
            //the element that i take as the last guy must be presenet in the new first or new last positions
            int temp=nums[k]*nums[i-1]*nums[j+1] + lastGuy(i,k-1,nums) + lastGuy(k+1,j,nums);
            ans=max(ans,temp);
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        nums.push_back(1);
        nums.insert(nums.begin(),1);              
        dp.resize(nums.size(),vector<int>(nums.size(),-1));
        return lastGuy(1,nums.size()-2,nums);        
    }
};