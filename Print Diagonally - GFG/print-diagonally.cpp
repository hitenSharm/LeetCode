//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
	    vector<int>ans;
	    for(int j=0;j<a[0].size();j++)
	    {
	        int tj=j;
	        int ti=0;
	        while(tj>=0 and ti<n)
	        {
	            ans.push_back(a[ti][tj]);
	            tj--;
	            ti++;
	        }
	    }
	    for(int i=1;i<n;i++)
	    {
	        int tj=a[0].size()-1;
	        int ti=i;
	        while(ti<n and tj>=0)
	        {
	            ans.push_back(a[ti][tj]);
	            tj--;
	            ti++;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends