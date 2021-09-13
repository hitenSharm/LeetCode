// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition

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
  long long int cal(long long int N,long long int power,long long int MOD){
      if(N==0 || N==1) return N%MOD;

      if(power==0) return 1;

      if(MOD==1) return 0;

      long long int ans=1;

        while(power){
            if(power%2){
               ans=(ans*N)%MOD;
            }
            N=(N*N)%MOD;
            power/=2;
        }
    return ans;
  }
    
    int numSubseq(vector<int>& nums, int target) {
        long long int ans=0;
        long long mod=1000000007;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(2*nums[i]>target)break;
            else
            {
                int l=i,r=nums.size()-1;
                int j=i;
                while(l<=r)
                {
                    int m=l+(r-l)/2;
                    if(nums[m]+nums[i]>target)
                    {
                        r=m-1;
                    }
                    else
                    {
                        j=m;
                        l=m+1;
                    }
                }
                if(nums[i]*2<=target)
                ans+=cal(2,j-i,mod);
                else
                ans+=cal(2,(j-i),mod)-1;
            }
        }
        return ans%mod;
    }
};