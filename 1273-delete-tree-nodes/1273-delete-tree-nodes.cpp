class Solution {
public:
    
    unordered_map<int,vector<int>>adj;    
    vector<int>sumBelow;
    int rem=0;
    
    int dfs(int curr,vector<int>& values)
    {
        if(adj.find(curr)==adj.end()){
            //leaf node            
            return sumBelow[curr]=values[curr];
        }        
        vector<int>& candi=adj[curr];        
        int val=values[curr];
        for(auto i:candi)
        {
            int x=dfs(i,values);
            val+=x;
        }        
        return sumBelow[curr]=val;
    }
    int getKids(int curr)
    {        
        int ans=1;
        if(adj.find(curr)!=adj.end())
        for(auto i:adj[curr]){
            ans+=getKids(i);
        }
        return ans;
    }
    void countZeroes(int curr)
    {
        if(sumBelow[curr]==0){
            rem+=getKids(curr);
            return ;
        }
        for(auto i:adj[curr])
        {
            countZeroes(i);
        }
    }
    
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        //adj[0].push_back({});
        for(int i=1;i<parent.size();i++)
        {            
            adj[parent[i]].push_back(i);
            //make graph
        }
        sumBelow.resize(nodes,0);
        //store the sum below each node
        sumBelow[0]=dfs(0,value);                                
        //now do a bfs/level order and 
        countZeroes(0);
        return nodes-rem;
    }
};