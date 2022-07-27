class Solution {
public:
    
    void dfs(unordered_set<int>& vis,int curr,vector<vector<int>>& rooms)
    {
        if(vis.size()==rooms.size())return ;
        vis.insert(curr);        
        vector<int>& candidates=rooms[curr];
        for(int i=0;i<candidates.size();i++)
        {
            if(vis.find(candidates[i])!=vis.end())continue ;
            dfs(vis,candidates[i],rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>vis;        
        dfs(vis,0,rooms);
        if(vis.size()==rooms.size())return true;
        
        return false;
    }
};