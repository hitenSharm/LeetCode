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
            int mini=-1;
            bool found=true;
            for(int j=0;j<temp.length();j++)
            {
                if(orig.find(temp[j])==orig.end())
                {
                    found=false;
                    break;
                }
                vector<int>& curr=orig[temp[j]];
                auto it=upper_bound(curr.begin(),curr.end(),mini);
                if(it==curr.end())
                {
                    found=false;
                    break;
                }
                else
                {
                    mini=*it;                    
                }
            }            
            ans+=found;
        }
        return ans;
        
    }
};