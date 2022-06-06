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
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>ump;
		
		for(int i=0;i<words.size();i++)
		ump[words[i]]++;
		
		int lc=0,l=0;
		for(int i=0;i<words.size();i++)
		{
			string s=words[i];
            if(ump[s]==0)continue;
			string rev = string(s.rbegin(), s.rend());
			ump[s]--;
			if(ump[rev]>0)
			{                
				l=l+(2*s.size());
				ump[rev]--;
				continue ;
			}
			if(s==rev and lc<s.size())
			{
				l=l-lc;
				lc=s.size();
				l+=lc;
			}			
		}
		return l;

    }
};