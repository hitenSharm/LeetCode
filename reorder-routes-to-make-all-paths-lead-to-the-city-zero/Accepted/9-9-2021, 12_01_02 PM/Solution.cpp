// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<int>vis;
        unordered_map<int,vector<int>>adjList;
        unordered_set<string>st;
        for(int i=0;i<connections.size();i++)
        {
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
            string temp=to_string(connections[i][0])+","+to_string(connections[i][1]);
            st.insert(temp);
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
                        string temp=to_string(candid[j])+","+to_string(c);
                        if(st.find(temp)==st.end())ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};