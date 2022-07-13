// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:

    int bs(int arr[],int n,int tofind)
    {
        tofind=tofind*2;
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]<=tofind)
            {
                ans=m;
                l=m+1;
            }
            else
            r=m-1;
        }
        return ans;
    }

	int minRemoval(int arr[], int n) {
	    sort(arr,arr+n);
	    int ans=INT_MAX;
	    for(int i=0;i<n-1;i++)
	    {
	        int justGreater=bs(arr,n,arr[i]);
	      // cout<<arr[i]<<" "<<justGreater<<" \n";
	        if(justGreater>=0)
	        ans=min(ans,n-1-justGreater+i);
	        else
	        ans=min(ans,i);
	    }
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
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.minRemoval(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends