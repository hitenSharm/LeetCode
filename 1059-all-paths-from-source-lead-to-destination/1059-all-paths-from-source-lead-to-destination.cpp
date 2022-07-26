class Solution {
public:
    
    int dfs(unordered_map<int,vector<int>>& adj,vector<int>& vis,vector<int>& inDfs,int c,int d)
    {
        if(adj[c].size()==0 and c!=d)return 0;
        if(vis[c]!=-1)return vis[c];
        inDfs[c]=1;
        int ans=1;
        for(int i=0;i<adj[c].size();i++)
        {
            if(inDfs[adj[c][i]]==1)return vis[c]=0;
            ans=dfs(adj,vis,inDfs,adj[c][i],d);
            if(ans==0)break ;
        }
        inDfs[c]=0;
        return vis[c]=ans;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>vis(n,-1);
        vector<int>inDfs(n,-1);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        int ans = dfs(adj,vis,inDfs,source,destination);
        return (ans==1);
    }
};