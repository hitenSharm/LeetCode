//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    vector<int>colors;
    bool valid(int c,int i,bool graph[101][101],int n)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j] and colors[j]==c)return false;
        }
        return true;
    }
    
    bool recu(bool graph[101][101],int m,int n,int idx)
    {
        if(idx>=n)return true;
        for(int c=0;c<m;c++)
        {
            if(valid(c,idx,graph,n)){
                //can colour
                colors[idx]=c;
                if(recu(graph,m,n,idx+1))return true;
                colors[idx]=-1;
            }
        }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        //recursive method is just try all possibities
        colors.resize(n,-1);
        return recu(graph,m,n,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends