//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int i=0,j=0;
        long long su=0;
        
        if(s==0){
            for(int i=0;i<n;i++)
            {
                if(arr[i]==0)return {i+1,i+1};
            }
            return {-1};
        }
        
        while(i<n)
        {
            if(su==s)return {i+1,j};
            while(j<n and su<s)
            {
                su+=arr[j];
                j++;
            }
            if(su==s){
                return {i+1,j};
            }
            su-=arr[i];
            i++;
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends