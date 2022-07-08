// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	vector<int>dp;
	int recu(int arr[],int index,int& n)
	{
		if(index>=n)return 0;
		if(dp[index]!=-1)return dp[index];
		int curr=arr[index];
		int ans=curr;
		for(int i=index+1;i<n;i++)
		{
		    if(arr[i]>arr[index])
			ans=max(ans,curr+recu(arr,i,n));
		}
		return dp[index]=ans;
	}

	int maxSumIS(int arr[], int n)  
	{  
	    dp.resize(n,-1);
		int ans=0;
	    for(int i=0;i<n;i++)
	    {
	    	ans=max(ans,recu(arr,i,n));
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
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends