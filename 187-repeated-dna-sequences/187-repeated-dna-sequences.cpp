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
    vector<string> findRepeatedDnaSequences(string s) {
        string tmp="";
        unordered_map<string,int>ump;
        int i=0,j=0;
        vector<string>ans;
        while(j<s.size())
        {
            while(j<s.size() and j-i<10)
            {
                tmp+=s[j];
                j++;
            }
            ump[tmp]++;
            if(ump[tmp]==2)ans.push_back(tmp);
            tmp.erase(0,1);
            i++;
        }
        return ans;
    }
};