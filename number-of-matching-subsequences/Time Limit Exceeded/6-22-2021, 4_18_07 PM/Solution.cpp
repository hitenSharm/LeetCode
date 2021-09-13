// https://leetcode.com/problems/number-of-matching-subsequences

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

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>orig;    
        for(int i=0;i<s.length();i++)
        {
            orig[s[i]].push_back(i);
        }
        int ans=0;
        
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            int mini=s.size()+1;
            int len=temp.length();
            unordered_set<int>vis;            
            for(int j=0;j<temp.length();j++)
            {
                if(orig.find(temp[j])==orig.end())
                break;
                vector<int>curr=orig[temp[j]];
                for(int k=0;k<curr.size();k++)
                {
                    if(vis.find(curr[k])!=vis.end())continue;
                    if(mini!=s.size()+1 and curr[k]<mini)continue;
                    else
                    {                           
                        vis.insert(curr[k]);
                        len--;
                        mini=curr[k];
                        break;
                    }
                }
            }            
            if(len==0){            
            ans++;            
            }
        }
        return ans;
        
    }
};