// https://leetcode.com/problems/palindrome-pairs

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string,int>ump;
        for(int i=0;i<words.size();i++)
        {
            ump[words[i]]=i;
        }
        vector<vector<int>>ans;
        
        for(int i=0;i<words.size();i++)
        {
            string temp=words[i];
            string rev=string(temp.rbegin(),temp.rend());
            if(temp=="")
            {
                for(int j=0;j<words.size();j++)
                {
                    if(i!=j and words[j]==string(words[j].begin(),words[j].end()))
                    {
                        ans.push_back({i,j});
                        ans.push_back({j,i});
                    }
                }
                continue;
            }
            if(ump.find(rev)!=ump.end() and temp.length()!=1)
            {
                ans.push_back({i,ump[rev]});
            }            
            for(int cut=1;cut<=temp.length();cut++)
            {
                string tmp=temp.substr(0,cut);
                if(tmp==string(tmp.rbegin(),tmp.rend()))
                {
                    string tmp2=temp.substr(cut);
                    reverse(tmp2.begin(),tmp2.end());
                    if(tmp2.length()>0 and ump.find(tmp2)!=ump.end())
                    {
                        ans.push_back({ump[tmp2],i});
                    }
                }
            }
            for(int cut=temp.length()-1;cut>0;cut--)
            {
                string tmp=temp.substr(temp.length()-cut,temp.length());
                if(tmp==string(tmp.rbegin(),tmp.rend()))
                {
                    string tmp2=temp.substr(0,temp.length()-cut);
                    reverse(tmp2.begin(),tmp2.end());
                    if(tmp2.length()>0 and ump.find(tmp2)!=ump.end())
                    {
                        ans.push_back({i,ump[tmp2]});
                    }
                }
            }
        }
        
        return ans;
    }
};