// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    double waterOverflow(int k, int R, int C) {
        vector<vector<double>>vec(k+1,vector<double>(k+1,0));
		int si=1,sj=1;
		vec[si][sj]=k*1.0;
		while(si!=vec.size()-1 and sj!=vec.size()-1)
		{
			sj=1;
			while(sj<=si)
			{
				double inside=vec[si][sj];
				if(inside>1)
				{
					vec[si][sj]=1.0;
					inside--;
					vec[si+1][sj]+=inside/2;
					vec[si+1][sj+1]+=inside/2;
				}
				sj++;
			}
			si++;
		}
		return vec[R][C];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout <<setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}  // } Driver Code Ends