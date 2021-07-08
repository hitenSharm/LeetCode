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

    static bool cmp(pair<char,int>& a,pair<char,int>& b)
    {
        return (a.second<b.second);
    }

    int minDeletions(string s) {
        unordered_map<char,int>ump;
        
        for(int i=0;i<s.length();i++)
        ump[s[i]]++;
        
        vector<pair<char, int>> elems(ump.begin(), ump.end());
        
        sort(elems.begin(),elems.end(),cmp);
        unordered_set<int>vis;
        int dele=0;
        
        for(int i=0;i<elems.size();i++)
        {
            int x=elems[i].second;
            while(x>0 and vis.find(x)!=vis.end())
            {
                x--;
                dele++;
            }
            
            if(x!=0)
            vis.insert(x);
        }
        return dele;
    }
};