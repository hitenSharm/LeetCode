#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
	int dp[2501];
	int recu(vector<int>& nums,int i)
	{
		if(i>=nums.size())return 0;
		if(dp[i]!=-1)return dp[i];
		int maxi=0;
		for(int j=i+1;j<nums.size();j++)
		{
			if(nums[j]>nums[i])
			{
				maxi=max(maxi,1+recu(nums,j));
			}
		}
		return dp[i]=maxi;
	}

    int lengthOfLIS(vector<int>& nums) {		
		memset(dp,-1,sizeof(dp));
        int len=1;
        for(int i=0;i<nums.size();++i){
            len=max(len,1+recu(nums,i));
        }
		return len;
    }
};