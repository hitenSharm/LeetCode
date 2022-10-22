//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod=100000000;
    vector<int>dp;
    int recu(int n)
    {
        if(n==0)return 1;
        if(n<0) return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=(recu(n-1)+recu(n-2))%mod;
    }
  
    int fillingBucket(int N) {
        dp.resize(N+1,-1);
        return recu(N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends