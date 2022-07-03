// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<vector<int>>arr;
        for(int i=0;i<n;i++)
        {
            vector<int>temp{start[i],end[i]};
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        int ans=1;
        int currEnd=arr[0][1];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i][0]<=currEnd)
            {
                currEnd=min(currEnd,arr[i][1]);            
            }
            else
            {
                ans++;
                currEnd=arr[i][1];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends