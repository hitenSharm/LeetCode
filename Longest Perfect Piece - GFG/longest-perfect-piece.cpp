//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    unordered_map<int,int>ump;
    
    bool isValid()
    {
        if(ump.size()==0)return true;
        if(ump.size()>2)return false;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it:ump)
        {
            mini=min(it.first,mini);
            maxi=max(maxi,it.first);
        }
       // cout<<maxi<<" "<<mini<<endl;
        return (maxi-mini<=1);
    }
    
    int longestPerfectPiece(int arr[], int n) {
        int i=0,j=0;
        int ans=0;
        while(i<n)
        {
            while(j<n)
            {
                ump[arr[j]]++;
                if(!isValid()){
                    ump[arr[j]]--;
                    if(ump[arr[j]]==0)ump.erase(arr[j]);
                    break;
                }
                j++;
            }
            ans=max(ans,j-i);
            ump[arr[i]]--;
            if(ump[arr[i]]==0)ump.erase(arr[i]);
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends