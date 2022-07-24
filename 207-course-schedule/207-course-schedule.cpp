class Solution {
public:
    int fl=0;
    void dfs(vector<int>& vis,unordered_map<int,vector<int>>& adj,int c,vector<int>& inDfs)
    {
        if(fl==1)return ;
        vis[c]=1;
        inDfs[c]=1;
        vector<int> candi=adj[c];
        for(int i=0;i<candi.size();i++)
        {                                   
            if(inDfs[candi[i]]==1){
                fl=1;
                return ;
            }
            if(vis[candi[i]]==1)continue ; 
            dfs(vis,adj,candi[i],inDfs);
        }        
        inDfs[c]=0;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>inDfs(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==1)continue ;            
            dfs(vis,adj,i,inDfs);
        }
        if(fl==1)return false;
        return true;
    }
};