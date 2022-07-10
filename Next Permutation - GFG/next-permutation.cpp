// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void swapping(vector<int>& arr,int start,int end)
	{
		while(start<end)
		{
			swap(arr[start],arr[end]);
			start++;
			end--;
		}
	}
    vector<int> nextPermutation(int N, vector<int> arr){
        int lastPeakIndex=-1;
        for(int i=arr.size()-2;i>=0;i--)
        {
        	if(arr[i]<arr[i+1])
        	{
        		lastPeakIndex=i+1;
        		break ;
        	}
        }
        if(lastPeakIndex==-1)
        {
        	swapping(arr,0,arr.size()-1);
        	return arr;
        }
        int toSwapIndex=lastPeakIndex-1;
        for(int i=arr.size()-1;i>=lastPeakIndex;i--)
        {
        	if(arr[i]>arr[toSwapIndex])
        	{
        		swap(arr[i],arr[toSwapIndex]);
        		break;
        	}
        }
        swapping(arr,lastPeakIndex,arr.size()-1);
        return arr;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends