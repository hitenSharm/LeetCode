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
    int numWays(string s) {
        int oc=0;
		long long int mod=1000000007;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')oc++;
		if(oc%3!=0)return 0;
		if(oc==0)return (((s.size()-1)*(s.size()-2)/2)%mod);		
		int cnt=0;
        long long int t1=0;
		long long int t2=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='1')cnt++;			
            if(cnt==(1*(oc/3)))t1++;
            if(cnt==(2*(oc/3)))t2++;
            if(cnt>(2*(oc/3)))break;
		}
		
		return ((t1*t2)%mod);
    }
};