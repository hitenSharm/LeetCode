// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int dp[1001][4];
	int recu(vector<int>& nums,int i,int size)
	{		
		if(size==3)return 1;
		if(dp[i][size]!=-1)return dp[i][size];
		int ans=0;
		for(int j=i+1;j<nums.size();j++)
		{
			if(nums[j]>nums[i])ans+=recu(nums,j,size+1);
		}
		return dp[i][size]=ans;
	}
	
	int countTriplets(vector<int>nums){
	    memset(dp,-1,sizeof(dp));
	    int ans=0;
		for(int i=0;i<nums.size();++i)
		ans+=recu(nums,i,1);
		return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends