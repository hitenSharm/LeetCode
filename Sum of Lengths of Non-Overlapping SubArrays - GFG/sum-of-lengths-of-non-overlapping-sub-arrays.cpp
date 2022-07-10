// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int calculateMaxSumLength(int arr[], int n, int k)
	{
		int i=0,j=0;
        int ans=0;
        while(i<n)
        {
            int maxi=0;
        	while(j<n and arr[j]<=k)
        	{
        		maxi=max(maxi,arr[j]);
        		j++;
        	}
        	if(maxi==k)ans+=(j-i);
        	i=j+1;
        	j=i;
        }
        return ans;
	}
		 

};

// { Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n, tmp;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	   	}
	   	cin>>tmp;
            
        
        

        Solution ob;
		cout << ob.calculateMaxSumLength(arr, n, tmp);
        
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends