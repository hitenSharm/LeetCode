//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string getString(string& s, int i, int j)
    {
        string ans = "";
        for (int k = i; k <= j; k++)ans += s[k];
        return ans;
    }
    string maxSum(string s, char x[], int b[], int n) {
        unordered_map<char, int>ump;
        for (int i = 0; i < n; i++)
        {
            ump[x[i]] = b[i];
        }        
        int i = 0,j = 0;
        int ai;
        int maxAns=INT_MIN, maxSoFar = 0;
        for (int k = 0; k < s.size(); k++)
        {
            if (ump.find(s[k]) != ump.end()) {
                maxSoFar += ump[s[k]];
            }
            else {
                int x = s[k];
                maxSoFar += x;
            }
            if (maxAns < maxSoFar)
            {
                ai = i;
                j = k;
                maxAns = maxSoFar;
            }
            if (maxSoFar < 0) {
                i = k+1;                
                maxSoFar = 0;
            }
        }
        return getString(s, ai, j);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends