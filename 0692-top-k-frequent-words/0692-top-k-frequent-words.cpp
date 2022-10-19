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
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>ump;
        for(auto i:words){
            ump[i]++;
        }
        unordered_map<int,set<string>>freq;
        for(auto it:ump)
        {
            freq[it.second].insert(it.first);
        }
        vector<string>ans;
        for(int i=10;i>=0;i--)
        {
            if(k==0)break;
            if(freq.find(i)==freq.end())continue;
            set<string>& temp=freq[i];
            for(auto it:temp)
            {
                ans.push_back(it);
                k--;
                if(k==0)return ans;
            }
        }
        return ans;
    }
};