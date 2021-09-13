// https://leetcode.com/problems/count-primes

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
    int countPrimes(int n) {
        if(n==0 || n==1)return 0;
        vector<int>primes(n+1,0);
        for(int i=2;i*i<=n;i++)
        {
            if(primes[i]==1)continue;
            for(int j=i*i ; j<=n ; j+=i)
            {
                primes[j]=1;
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++)
        {
            if(primes[i]==0)cnt++;
        }
        return cnt;
    }
};