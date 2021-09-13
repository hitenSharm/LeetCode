// https://leetcode.com/problems/design-add-and-search-words-data-structure

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
    unordered_map<char,vector<char>>adjList;
    unordered_map<char,int>freq;
    void addWord(string word) {
        
        for(int i=0;i<word.size();i++)freq[word[i]]++;
        for(int i=1;i<word.length();i++)
        {
            adjList[word[i-1]].push_back(word[i]);
        }
        adjList[word[word.length()-1]].push_back(word[word.length()-1]);
    }
    
    bool dfs(int index,string& word)
    {
        if(index>=word.size())return true;
        bool ans=false;
        if(word[index]=='.')
        {
            for(auto it:adjList)
            {
                if(freq[it.first]>=1)
                {
                    freq[it.first]--;
                    ans=ans||dfs(index+1,word);
                    freq[it.first]++;
                }
                else
                continue;
                if(ans)return ans;
            }
        }
        else
        {
            for(auto it:adjList)
            {
                if(it.first==word[index] and freq[word[index]]>=1)
                {
                    freq[word[index]]--;
                    ans=ans||dfs(index+1,word);
                    freq[it.first]++;
                }
                else
                continue;
                if(ans)return ans;
            }
        }
        return false;
    }
    
    bool search(string word) {
        int i=0;
        return dfs(i,word);
    }
};
