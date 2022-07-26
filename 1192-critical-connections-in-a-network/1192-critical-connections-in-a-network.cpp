class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> graph;
    vector<int> id;
    vector<int> lowLink;
    vector<bool> vis;
    int time=0;
    
    void dfs(int curr,int parent)
    {
        id[curr]=lowLink[curr]=time++;
        vis[curr]=true;
        for(int &x:graph[curr]){
            if(parent==x)continue ;
            if(vis[x]){
                //update min start from the visited node
                lowLink[curr]=min(lowLink[curr],lowLink[x]);
                continue ;
            }
            dfs(x,curr);
            lowLink[curr]=min(lowLink[curr],lowLink[x]);//update min start time based on all choild nodes which are not parent
            if(id[curr]<lowLink[x])//startTime[curr] < minStart of child
            {
                ans.push_back({x,curr});//min start se nahi compare kar sakte, say u get the min start time from right direction
                //recursively u r going l->r so startime u get from left side and min from right side
                //if when cheking for bridg i am saying what if i make a cut from the side of node i get min start time from,(right side)
                //i will get wrinkg answer, i shud check based on the recursively discorvered start time and min start of child nodes
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        vis.resize(n,false);
        lowLink.resize(n,0);
        id.resize(n,0);
        for(auto &x:connections)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false)
                dfs(i,i);
        }
        return ans;
    }
};