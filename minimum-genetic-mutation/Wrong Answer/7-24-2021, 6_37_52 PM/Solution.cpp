// https://leetcode.com/problems/minimum-genetic-mutation

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
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>valids;
        
        for(int i=0;i<bank.size();i++)
        valids.insert(bank[i]);
        
        queue<pair<string,int>>q;
        for(int i=0;i<start.length();i++)
        {
            if(start[i]!=end[i])q.push({start,i});
        }
        int changes=0;
        while(!q.empty())
        {
            int len=q.size();
            for(int k=0;k<len;k++)
            {
                pair<string,int>temp=q.front();
                q.pop();
                temp.first[temp.second]=end[temp.second];
                if(valids.find(temp.first)==valids.end())continue;
                if(temp.first==end)return changes+1;
                for(int i=0;i<start.length();i++)
                {
                    if(temp.first[i]!=end[i])q.push({temp.first,i});
                }
            }
            changes++;
        }
        return -1;
    }
};