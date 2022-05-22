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
		int i=0,j=0;
		while(i<s.size())
		{
			ans+=palin(s,i,j);
			if(j+1<s.size())
			{
				j++;
				ans+=palin(s,i,j);
			}
			i++;
		}
		return ans;
    }
};