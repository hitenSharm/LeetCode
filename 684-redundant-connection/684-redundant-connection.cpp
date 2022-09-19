class Solution {
public:
    int p[1001];
    int r[1001];
    //ranks is like levels in the tree
    int findParent(int n)
    {
        if(n==p[n])return n;
        //recursively find mega parent in the dsu
        return p[n]=findParent(p[n]); //path compression
    }
    
    void insertDsu(int v1,int v2)
    {
        int parent=findParent(v1);
        int parent2=findParent(v2);
        if(r[parent]<r[parent2])
        {
            p[v1]=parent2;
        }
        else if(r[parent]>r[parent2]) //parent rank
        {
            p[v2]=parent;
        }
        else
        {
            p[v2]=parent;
            r[parent]++;
        }
    }
    //tc constant in amortized time complexity for dsu part, overall its linear
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {        
        for(int i=0;i<1001;i++)
        {
            p[i]=i;
            r[i]=0;
        }
        int ans;
        for(int i=0;i<edges.size();i++)
        {                        
            int parent1=findParent(p[edges[i][1]]);
            int parent2=findParent(p[edges[i][0]]);
            if(parent1==parent2)ans=i;
            //this needs to be checked first!!!! if parents are same
            // => both can follow a path and get to same point
            // and as it is in edges this means there is a path from i1,i2
            // therefore part of a cycle!
            
            p[parent1]=parent2; //this is being done without path compression
            
        }
        return edges[ans];
    }
};