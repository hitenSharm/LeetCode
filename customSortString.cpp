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
    string customSortString(string order, string str) {
        unordered_map<char,int>ump;
        
        for(int i=0;i<str.length();i++)
        ump[str[i]]++;
        
        string ans="";
        
        int len=0;
        while(len<order.length())
        {
            char temp=order[len];
            while(ump.find(temp)!=ump.end())
            {
                ans.push_back(temp);
                ump[temp]--;
                if(ump[temp]==0)
                ump.erase(temp);
            }
            len++;
        }
        for(auto it:ump)
        {
            int tmp=it.second;
            while(tmp>0)
            {
                ans.push_back(it.first);
                tmp--;
            }
        }
        return ans;
    }
};