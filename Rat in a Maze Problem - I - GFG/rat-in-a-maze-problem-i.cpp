// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    
    void recu(string& res,vector<vector<int>> &m,int n,int i,int j)
    {
        
        if(i==n-1 and j==n-1)
        {
            ans.push_back(res);
            return ;
        }
        if(i+1<n and m[i+1][j]==1)
        {
            m[i][j]=0;
            res+="D";
            recu(res,m,n,i+1,j);
            res.pop_back();
            m[i][j]=1;
        }
        if(j+1<n and m[i][j+1]==1)
        {
            m[i][j]=0;
            res+="R";
            recu(res,m,n,i,j+1);
            res.pop_back();
            m[i][j]=1;
        }
        if(i-1>=0 and m[i-1][j]==1)
        {
            m[i][j]=0;
            res+="U";
            recu(res,m,n,i-1,j);
            res.pop_back();
            m[i][j]=1;
        }
        if(j-1>=0 and m[i][j-1]==1)
        {
            m[i][j]=0;
            res+="L";
            recu(res,m,n,i,j-1);
            res.pop_back();
            m[i][j]=1;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string res="";
        if(m[0][0]==1)
        recu(res,m,n,0,0);
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends