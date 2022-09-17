class Solution {
public:
    
    vector<int>indegree;
    vector<int>ans;
    unordered_map<int,vector<int>>adj;
    void kahns()
    {
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            ans.push_back(curr);
            vector<int>& candid=adj[curr];
            for(auto i:candid)
            {
                if(indegree[i]>0)
                {
                    indegree[i]--;
                    if(indegree[i]==0)q.push(i);
                }
            }
        }
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        //kahns algorithm is better here, other option is topo with cycle dtection using dfs  
        indegree.resize(numCourses);
        for(int i=0;i<pre.size();i++)
        {
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        kahns();
        if(ans.size()!=numCourses)ans.clear();
        return ans;
    }
};