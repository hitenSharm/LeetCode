//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>>ans;
	vector<int>temp;
	
	void recu(int s,int i)
	{
	    if(s<0 || i<=0)return ;
	    if(s==0)
	    {
	        ans.push_back(temp);
	        return ;
	    }
	    
	    temp.push_back(i);
	    recu(s-i,i);
	    temp.pop_back();
	    recu(s,i-1);
	}
	
    vector<vector<int>> UniquePartitions(int n) {
        // vector<int>nums;
        // for(int i=1;i<=n;i++)
        // {
        //     nums.push_back(i);
        // }
        recu(n,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends