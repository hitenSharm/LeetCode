// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int bs(vector<int>& v)
		{
			int l=0,r=v.size()-1;
			int ans=-1;
			while(l<=r)
			{
				int m=l+(r-l)/2;
				if(v[m]==0)l=m+1;
				else
				{
					ans=m;
					r=m-1;
				}
			}
			return ans;
		}
	
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int ans=0;
            int r;
			for(int i=0;i<N;++i)
			{
				int index=bs(Mat[i]);
				if(index!=-1 and ans<M-index)
				{
				    ans=M-index;
				    r=i;
				}
			}
			return r;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends