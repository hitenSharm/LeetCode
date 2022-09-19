class Solution {
public:
    int p[2001];
    int siz[2001];
    
    int findParent(int node)
    {
        if(node==p[node])return node;
        
        return p[node]=findParent(p[node]);
    }
    
    int insertDsu(int a,int b)
    {
        a=findParent(a);
        b=findParent(b);
        if(a==b)return 0;
        
        if(siz[a]>siz[b])swap(a,b);
        //attach smaller to larger tree always!
        //a is smaller one abd b is larger one
        p[a]=b;
        siz[b]+=siz[a];
        return 1;
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<2001;i++)
        {
            p[i]=i;
            siz[i]=1;
        }
        
        for(auto i:edges)
        {   
            n-=insertDsu(i[0],i[1]);
        }
        
        return n;
    }
};