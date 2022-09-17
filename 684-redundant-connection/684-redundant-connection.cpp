class Solution {
public:
    
    unordered_map<int,vector<int>>adj;
    set<pair<int,int>>cycle;
    unordered_set<int>vis;
    int dfs(int curr,int p)
    {
        if(vis.find(curr)!=vis.end())return curr;
        vector<int>& candi=adj[curr];
        vis.insert(curr);
        int x=-1;
        for(auto i: candi)
        {
            if(i==p)continue ;
            x=dfs(i,curr);
            if(x!=-1 and x!=curr)
            {
               // cout<<i<<" "<<curr<<endl;
                cycle.insert({i,curr});
                cycle.insert({curr,i});
                return x;
            }
            else if(x!=-1 and x==curr)
            {
                cycle.insert({i,curr});
                cycle.insert({curr,i});
                return -1;
            }
        }
        return -1;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //collect all part of cycle nodes
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(1,-1);
        for(int i=edges.size()-1;i>=0;i--)
        {
            if(cycle.find({edges[i][0],edges[i][1]})!=cycle.end())return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};