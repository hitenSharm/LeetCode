// https://leetcode.com/problems/push-dominoes

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
    string pushDominoes(string dominoes) {
		vector<int>force;
		int len=dominoes.length();
		int f=0;
		for(int i=0;i<len;i++)
		{
			if(dominoes[i]=='R')
			{
				f=len;
			}
			else if(dominoes[i]=='L')
			{
				f=0;
			}
			else
				f=max(f-1,0);
			force.push_back(f);
		}
		for(int i=len-1;i>=0;i--)
		{
			if(dominoes[i]=='L')
			{
				f=len;
			}
			else if(dominoes[i]=='R')
			{
				f=0;
			}
			else
				f=max(f-1,0);
			force[i]=force[i]-f;
		}
		string ans;
		for(int i:force)
		{
			if(i>0)
				ans.push_back('R');
			else if(i<0)
				ans.push_back('L');
			else
				ans.push_back('.');
		}
		return ans;
    }
};