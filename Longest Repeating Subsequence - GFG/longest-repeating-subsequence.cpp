// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    vector<vector<int>>dp;
	    int lcs(string& str1,string& str2,int i,int j)
	    {
	        if(i>=str1.size() || j>=str2.size())return 0;
	        if(dp[i][j]!=-1)return dp[i][j];
	        if(i==j || str1[i]!=str2[j])
	        {
	            return dp[i][j]=max(lcs(str1,str2,i+1,j),lcs(str1,str2,i,j+1));
	        }
	        return dp[i][j]=(1+lcs(str1,str2,i+1,j+1));
	    }
	
		int LongestRepeatingSubsequence(string str){
		    dp.resize(str.size(),vector<int>(str.size(),-1));
		    string str2=str;
		    return lcs(str,str2,0,0);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends