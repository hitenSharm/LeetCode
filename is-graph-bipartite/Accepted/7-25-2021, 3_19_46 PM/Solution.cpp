// https://leetcode.com/problems/is-graph-bipartite

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();
//graph colouring algo
class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int colour[101];
        memset(colour,-1,sizeof(colour));
        unordered_set<int>vis;
        for(int i=0;i<n;i++)
        {
            if(colour[i]!=-1)continue ;
            if(colour[i]==-1)
            {                
                queue<int>q;
                q.push(i);
                colour[i]=0;
                while(!q.empty())
                {
                    int temp=q.front();q.pop();
                    vis.insert(temp);
                    for(int t=0;t<graph[temp].size();t++)
                    {
                        if(colour[temp]==0)
                        {
                            if(colour[graph[temp][t]]==0){
                                return false;
                            }
                            if(vis.find(graph[temp][t])==vis.end())
                            {
                                colour[graph[temp][t]]=1;
                                q.push(graph[temp][t]);
                            }
                        }
                        if(colour[temp]==1)
                        {
                            if(colour[graph[temp][t]]==1){                                
                                return false;
                            }
                            if(vis.find(graph[temp][t])==vis.end())
                            {
                                colour[graph[temp][t]]=0;
                                q.push(graph[temp][t]);
                            }
                        }
                    }
                    if(vis.size()==n)return true;
                }
            }
        }
        return true;
    }
};