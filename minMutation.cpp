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
        unordered_set<string>vis;
        
        for(int i=0;i<bank.size();i++)
        valids.insert(bank[i]);
        
        queue<string>q;
        q.push(start);
        int changes=0;
        char words[4]={'A','C','T','G'};
        while(!q.empty())
        {
            int len=q.size();
            for(int k=0;k<len;k++)
            {
                string temp=q.front();
                q.pop();
                vis.insert(temp);
                for(int i=0;i<temp.length();i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        if(words[j]==temp[i])continue;
                        char t=temp[i];
                        temp[i]=words[j];
                        if(valids.find(temp)!=valids.end())
                        {
                            if(temp==end)return changes+1;
                            else
                            {
                                if(vis.find(temp)==vis.end())
                                q.push(temp);
                            }
                        }
                        temp[i]=t;
                    }
                }
                
            }
            changes++;
        }
        return -1;
    }
};