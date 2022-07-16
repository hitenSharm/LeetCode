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
    // vector<int>vis;
    
    bool recu(int curr,vector<int>&color,int toColor,vector<vector<int>>& graph)
    {
        if(color[curr]==-1)color[curr]=toColor;
        else if(color[curr]!=toColor)return false;
       //i chekc to see if the color too be set as new colour is correct
        //if it is ==> this was mp visited b4r => vis[cur]==1 and so return
        //can also do color[curr]==toColor return true;
        else if(color[curr]==toColor)return true;
        
        // vis[curr]=1;
        vector<int>& candid=graph[curr];
        bool ans=true;
        for(int i=0;i<candid.size();i++)
        {            
            int newColor = (toColor == 0 ? 1 : 0 );
            ans = ans && recu(candid[i],color,newColor,graph);
        }
        return ans;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);    
        bool ans=true;
        // vis.resize(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]!=-1)continue ;
            ans=ans && recu(i,color,0,graph);
        }
        return ans;
    }
};