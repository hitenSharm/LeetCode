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
	int palin(string& s,int i,int j)
	{
		int ans=0;
		while(i>=0 and j<s.size() and s[i]==s[j])
		{
			ans++;
			i--;
			j++;
		}
		return ans;
	}

    int countSubstrings(string s) {
        if(s.size()==1)return 1;
        int ans=0;
		int i=0;
		while(i<s.size())
		{            
			ans+=palin(s,i,i);
			ans+=palin(s,i,i+1);
			i++;
		}
		return ans;
    }
};