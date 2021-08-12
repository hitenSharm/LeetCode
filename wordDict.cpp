#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class WordDictionary {
public:
    WordDictionary() {
    }
    unordered_map<int,vector<string>>ump;
    void addWord(string word) {
       ump[word.size()].push_back(word);
    }
    
    bool search(string word) {
        if(ump.find(word.size())==ump.end())return false;
        vector<string>& candids=ump[word.size()];
        for(int i=0;i<candids.size();i++)
        {
            if(word==candids[i])return true;
            else
            {
                int fl=0;
                for(int j=0;j<word.size();j++)
                {
                    if(word[j]=='.')continue;
                    if(word[j]!=candids[i][j])
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl==0)return true;
            }
        }
        return false;
    }
};
