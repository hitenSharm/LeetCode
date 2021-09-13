// https://leetcode.com/problems/smallest-string-with-swaps

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

    unordered_map<int,vector<int>>adjList;
    int vis[10001]={0};
    
    void dfs(int index,vector<int>& newIndexes,string& og)
    {
        vis[index]=1;
        newIndexes.push_back(index);
        vector<int>& candidates=adjList[index];        
        for(int i=0;i<candidates.size();i++)
        {
            if(vis[candidates[i]]==1)continue;
            dfs(candidates[i],newIndexes,og);
        }
        return ;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(int i=0;i<pairs.size();i++)
        {
            adjList[pairs[i][0]].push_back(pairs[i][1]);
            adjList[pairs[i][1]].push_back(pairs[i][0]);
        }
        for(int i=0;i<s.length();i++)
        {
            if(vis[i]==0)
            {
                vector<int>newIndexes;
                dfs(i,newIndexes,s);
                string temp="";
                for(int j=0;j<newIndexes.size();j++)
                {                    
                    temp+=s[newIndexes[j]];
                }                
                sort(temp.begin(),temp.end());                
                sort(newIndexes.begin(),newIndexes.end());
                for(int j=0;j<newIndexes.size();j++)
                {
                    s[newIndexes[j]]=temp[j];
                }
                newIndexes.clear();
            }
        }
        return s;
    }
};