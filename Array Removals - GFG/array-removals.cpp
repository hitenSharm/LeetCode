//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int getIndex(vector<int>& arr,int val)
    {
        int l=0,r=arr.size()-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            if(arr[m]<=val)
            l=m+1;
            else
            r=m-1;
        }
        return l;
    }
    
    int removals(vector<int>& arr, int k){
        sort(arr.begin(),arr.end());
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++)
        {
            int idx=getIndex(arr,arr[i]+k);
            //cout<<arr[i]<<" "<<arr[idx]<<endl;
            idx=(arr.size()-idx);
            ans=min(ans,i+idx);
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution ob;
        int ans = ob.removals(arr,k);
        
        cout<<ans<<endl;
    }
}



// } Driver Code Ends