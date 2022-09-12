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
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int ans=0;
        int res=0;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                ans++;
                res=max(ans,res);
                power-=tokens[i];
                i++;  
            }
            else if(ans>0)
            {
                ans--;
                power+=tokens[j];
                j--;
            }
            else
                break;
        }
        return res;
    }
};