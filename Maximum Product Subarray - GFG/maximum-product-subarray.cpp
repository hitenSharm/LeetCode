// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
        long long ans=arr[0];
        long long maxTillHere=1;
        for(int i=0;i<n;++i)
        {
            if(arr[i]==0)
            {                
                maxTillHere=1;
                continue ;
            }
            maxTillHere=maxTillHere*arr[i];
            ans=max(ans,maxTillHere);
        }
        maxTillHere=1;
        long long maxSofar=arr[n-1];
        for(int i=n-1;i>=0;--i)
        {
            if(arr[i]==0)
            {                
                maxTillHere=1;
                continue ;
            }
            maxTillHere=maxTillHere*arr[i];
            maxSofar=max(maxSofar,maxTillHere);
        }
        ans=max(ans,maxSofar);
        return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends