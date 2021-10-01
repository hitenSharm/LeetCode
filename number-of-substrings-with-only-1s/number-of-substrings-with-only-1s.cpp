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
    long long mod=1000000007;
    
    int numSub(string s) {
        long long ans=0;
        long long cnt=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')cnt++;
            else
            {
                ans+=(cnt*(cnt+1)/2);
                cnt=0;
            }
        }
        ans+=(cnt*(cnt+1)/2);
        return ans%mod;
    }
};