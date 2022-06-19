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
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int i=0,j=0;
        while(i<bank.size())
        {
            int c1=count(bank[i].begin(),bank[i].end(),'1');
            if(c1==0)
            {
                i++;
                continue ;
            }
            j=i+1;
            int c2=0;
            while(j<bank.size() and c2==0)
            {
                c2=count(bank[j].begin(),bank[j].end(),'1');
                if(c2==0)j++;
            }
            if(c2!=0)
            {
                i=j;
                ans+=(c1*c2);
            }
            else
            i++;
        }
        return ans;
    }
};