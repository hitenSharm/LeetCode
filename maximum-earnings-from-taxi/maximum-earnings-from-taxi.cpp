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
    vector<long long>dp;
    
    long long recu(int index,vector<vector<int>>& rides)
    {
        if(index==rides.size() || index==-1)return 0;
        if(dp[index]!=-1)return dp[index];
        int newIndex=-1;
        int l=index+1;
        int r=rides.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(rides[m][0]>=rides[index][1])
            {
                r=m-1;
                newIndex=m;
            }
            else
            l=m+1;
        }        
        long long a1=rides[index][1]-rides[index][0]+rides[index][2]+recu(newIndex,rides);        
        long long a2=recu(index+1,rides);
        return dp[index]=max(a1,a2);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        dp.resize(rides.size()+1,-1);
        sort(rides.begin(),rides.end());
        return recu(0,rides);
    }
};