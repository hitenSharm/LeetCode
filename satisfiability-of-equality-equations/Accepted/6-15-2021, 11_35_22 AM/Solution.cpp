// https://leetcode.com/problems/satisfiability-of-equality-equations

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
    
    unordered_map<char,vector<char>>equals;
    unordered_map<char,vector<char>>unequals;
    
    int contradiction(char start,char target)
    {
        int vis[26]={0};
        queue<char>bfs;
        bfs.push(start);
        vis[start-'a']=1;
        while(!bfs.empty())
        {
            char tmp=bfs.front();
            if(target==tmp)
            return 1;
            bfs.pop();
            vector<char>canids=equals[tmp];
            for(int i=0;i<canids.size();i++)
            {
                if(target==canids[i])
                return 1;
                else
                {
                    if(vis[canids[i]-'a']==0)
                    {
                        vis[canids[i]-'a']=1;
                        bfs.push(canids[i]);
                    }
                }
            }
        }
        return 0;
    }
    
    bool equationsPossible(vector<string>& equations) {
        for(int i=0;i<equations.size();i++)
        {
            string temp=equations[i];
            string ifelse=temp.substr(1,2);
            if(ifelse=="==")
            {
                equals[temp[0]].push_back(temp[3]);
                equals[temp[3]].push_back(temp[0]);
            }
            else
            {
                unequals[temp[0]].push_back(temp[3]);
                unequals[temp[3]].push_back(temp[0]);
            }
        }
        if(unequals.size()==0)
        return true;
        else
        {
            for(auto it:unequals)
            {
                vector<char>uneq=it.second;
                char start=it.first;
                for(int i=0;i<uneq.size();i++)
                {
                    if(contradiction(start,uneq[i])==1)
                    return false;
                }
            }
        }
        return true;
    }
};