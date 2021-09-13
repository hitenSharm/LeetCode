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

    void recu(int curr,int n,int k,vector<vector<int>>& ans,vector<int>& tmp)
    {
        if(k==0)
        {
            ans.push_back(tmp);
            return ;
        }
        for(int i=curr+1;i<=n;i++)
        {
            tmp.push_back(i);
            recu(i,n,k-1,ans,tmp);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>tmp;
        recu(0,n,k,ans,tmp);
        return ans;
    }
};