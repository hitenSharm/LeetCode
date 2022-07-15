class Solution {
public:
    typedef pair<int,int>pi;
    
    unordered_map<int,vector<pair<int,int>>>adjList;
    unordered_map<int,int>ump;
    
    int djikstra(int start,int maxi,int& n)
    {
        vector<int>vis(n,0);
        vector<int>dis(n,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,start});
        vis[start]=1;
        dis[start]=0;
        
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();            
            int curr=p.second;            
            vis[curr]=1;
            vector<pair<int,int>> candidates=adjList[curr];
            for(int i=0;i<candidates.size();i++)
            {
                int pathDist=candidates[i].second;
                int adjNode=candidates[i].first;                
                if(vis[adjNode]==1)continue ;
                if(dis[curr]+pathDist < dis[adjNode])
                {
                    dis[adjNode]=dis[curr]+pathDist;
                    if(dis[adjNode]<=maxi)
                    pq.push({dis[adjNode],adjNode});
                }
            }         
        }        
        int ans=0;
        for(int i=0;i<dis.size();i++)
        {            
            if(dis[i]<=maxi and i!=start)
                ans++;
        }             
        return ans;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int connectedTo=INT_MAX;
        int ans;
        for(int i=0;i<n;i++)
        {
            ump[i]=djikstra(i,distanceThreshold,n);
            if(connectedTo>=ump[i])
            {
                connectedTo=ump[i];
                ans=i;
            }
        }
        return ans;
    }
};