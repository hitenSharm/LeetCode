class Solution {
public:
    unordered_set<int>vis;
    unordered_map<int,vector<int>>adjList; 
    set<pair<int,int>>orig;
    
    void dfs(int node,int& ans)
    {
        vector<int>& candi=adjList[node];
        vis.insert(node);
        for(auto i:candi)
        {
            if(vis.find(i)!=vis.end())continue ;
            if(orig.find({node,i})!=orig.end())//as it is in orig i need to reverse to get to 0
                ans++;
            dfs(i,ans);
        }
    }     
    int minReorder(int n, vector<vector<int>>& connections) {        
        for(int i=0;i<connections.size();i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);     
            orig.insert({connections[i][0],connections[i][1]});
        }
        
        int ans=0;
        dfs(0,ans);   
        return ans;  
    }
};