// https://leetcode.com/problems/shortest-path-with-alternating-colors

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    
    struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    
    unordered_map<int, vector<int>>adjRed;
    unordered_map<int, vector<int>>adjBlue;

    int bfs(int &e,int& n)
    {
        if(e==0)return 0;
        
        queue<pair<int,char>>q;
        unordered_map<pair<int,char>,bool,hash_pair>vis;
        vector<int>dist(n,0);
        dist[0]=0;
        q.push({0,'N'});
        
        while(!q.empty())
        {
            pair<int,char>temp=q.front();
            q.pop();
            if(vis.find(temp)!=vis.end())continue;
            if(temp.second=='N')
            {
                vis[{0,'B'}]=true;
                vis[{0,'R'}]=true;
            }
            else
            vis[temp]=true;
            
            if(temp.second=='N')
            {
                vector<int>candRed=adjRed[temp.first];
                vector<int>candBlu=adjBlue[temp.first];
                
                for(int i=0;i<candBlu.size();i++)
                {
                    if(vis.find({candBlu[i],'B'})!=vis.end())continue;
                    dist[candBlu[i]]=dist[temp.first]+1;
                    q.push({candBlu[i],'B'});
                    if(candBlu[i]==e)
                    return dist[candBlu[i]];
                }
                
                for(int i=0;i<candRed.size();i++)
                {
                    if(vis.find({candRed[i],'R'})!=vis.end())continue;
                    dist[candRed[i]]=dist[temp.first]+1;
                    q.push({candRed[i],'R'});
                    if(candRed[i]==e)
                    return dist[candRed[i]];
                }
            }
            if(temp.second=='R')
            {
                vector<int>candBlu=adjBlue[temp.first];
                for(int i=0;i<candBlu.size();i++)
                {
                    if(vis.find({candBlu[i],'B'})!=vis.end())continue;
                    dist[candBlu[i]]=dist[temp.first]+1;
                    q.push({candBlu[i],'B'});
                    if(candBlu[i]==e)
                    return dist[candBlu[i]];
                }
            }
            if(temp.second=='B')
            {
                vector<int>candRed=adjRed[temp.first];
                for(int i=0;i<candRed.size();i++)
                {
                    if(vis.find({candRed[i],'R'})!=vis.end())continue;
                    dist[candRed[i]]=dist[temp.first]+1;
                    q.push({candRed[i],'R'});
                    if(candRed[i]==e)
                    return dist[candRed[i]];
                }
            }
            
        }
        return -1;
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int>ans(n);
        
        for(int i=0;i<red_edges.size();i++)
        adjRed[red_edges[i][0]].push_back(red_edges[i][1]);
        
        for(int i=0;i<blue_edges.size();i++)
        adjBlue[blue_edges[i][0]].push_back(blue_edges[i][1]);
        
        for(int i=0;i<n;i++)
        {
            ans[i]=bfs(i,n);
        }
        return ans;
    }
};