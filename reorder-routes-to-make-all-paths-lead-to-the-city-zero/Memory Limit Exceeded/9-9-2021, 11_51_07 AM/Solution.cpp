// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int>vis;
        unordered_map<int,vector<int>>adjList;
        vector<vector<int>>v(n,vector<int>(n,0));
        for(int i=0;i<connections.size();i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
            v[connections[i][0]][connections[i][1]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vis.find(i)!=vis.end())continue;
            queue<int>q;
            q.push(i);
            while(!q.empty())
            {
                vis.insert(q.front());
                int c=q.front();
                q.pop();
                vector<int>& candid=adjList[c];
                for(int j=0;j<candid.size();j++)
                {
                    if(vis.find(candid[j])==vis.end())
                    {
                        q.push(candid[j]);
                        if(v[candid[j]][c]==0)ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};