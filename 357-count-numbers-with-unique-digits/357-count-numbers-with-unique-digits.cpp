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

    int recu(int len,vector<int>vis,int currLen)
    {
        if(currLen>len)return 1;
        int ans=0;
        for(int i=(currLen == 1 ? 1 :0);i<=9;++i)
        {
            if(vis[i]==1)continue;
            vis[i]=1;
            ans+=recu(len,vis,currLen+1);
            vis[i]=0;
        }
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {        
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            vector<int>vis(10,0);
            ans+=recu(i,vis,1);
        }
        return ans+1;
    }
};