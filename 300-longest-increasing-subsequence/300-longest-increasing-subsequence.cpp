class Solution {
public:
//     int dp[2501][2501];
//     int recu(int prev,int i,vector<int>& nums)
//     {
//         if(i>=nums.size())return 0;
//         if(dp[prev+1][i]!=-1)return dp[prev+1][i];
//         int ans=recu(prev,i+1,nums);
//         if(prev==-1 || nums[prev]<nums[i])
//             ans=max(ans,1+recu(i,i+1,nums));
        
//         return dp[prev+1][i]=ans;
//     }
    int getLower(vector<int>& arr,int x)
    {
        int l=0,r=arr.size()-1;        
        while(l<=r)
        {
            int m = l+(r-l)/2;
            if(arr[m]>=x)
            {              
                r=m-1;
            }
            else
            {                
                l=m+1;
            }
        }
        return l;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(arr.size()==0 || arr.back()<nums[i])arr.push_back(nums[i]);
            else
            {
                 int l=getLower(arr,nums[i]);
                //cout<<l<<endl;
                 arr[l]=nums[i];
            }
        }
        return arr.size();
    }
};