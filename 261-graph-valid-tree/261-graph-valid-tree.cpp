class Solution {
public:
    int par[2001];
    int size[2001];
    
    int findParent(int n)
    {
        if(n==par[n])return n;
        
        return par[n]=findParent(par[n]);
    }
    
    bool dsu(int a,int b)
    {
        a=findParent(a);
        b=findParent(b);
        if(a==b)return true;
        if(size[a]>size[b])swap(a,b);
        //attach smaller to bigger
        
        par[a]=b;
        size[b]+=size[a];
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        //dfs on undirected cycle
        //bfs undirected is startigup check visited
        //best approach put in dsu and at each insert if getting same parent => cycle
        for(int i=0;i<=n;i++)
        {
            par[i]=i;
            size[i]=0;
        }
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
                        
            if(dsu(a,b))return false;
        }
        int p=findParent(0);
        for(int i=1;i<n;i++)
            if(p!=findParent(i))return false;
        
        return true;
    }
};