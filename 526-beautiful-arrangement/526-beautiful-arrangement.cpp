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

	void recu(int& ans,vector<int>vis,int& n,int curr)
	{
		if(curr==0)
		{
			ans++;
			return ;
		}		
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0 and (i%curr==0 || curr%i==0))
			{
				vis[i]=1;
				recu(ans,vis,n,curr-1);
				vis[i]=0;
			}
		}
		
	}

    int countArrangement(int n) {
        vector<int>vis(n+1,0);
		int ans=0;		
		recu(ans,vis,n,n);
		return ans;
    }
};