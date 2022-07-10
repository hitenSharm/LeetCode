// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

int countZeroes(int arr[], int n) {
    int l=0,r=n-1;
    int i;
    while(l<=r)
    {
    	int m =l+(r-l)/2;
    	if(arr[m]==1)
    		l=m+1;
    	else
    	{
    		i=m;
    		r=m-1;
    	}
    }
    return n-i;
}

// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);;
        }
        
        int ans = countZeroes(arr, n);
        printf("%d\n", ans);
    }
    return 0;
}
  // } Driver Code Ends