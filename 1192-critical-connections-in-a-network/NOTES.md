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
```