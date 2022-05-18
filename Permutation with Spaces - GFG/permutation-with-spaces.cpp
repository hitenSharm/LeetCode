// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    void recu(string s,int i,vector<string>& ans,string tmp)
    {
        if(i==s.size()-1)
        {
            tmp+=s[i];
            ans.push_back(tmp);
            return ;
        }
        tmp=tmp+s[i]+" ";
        recu(s,i+1,ans,tmp);
        tmp.pop_back();
        recu(s,i+1,ans,tmp);
    }
    
    vector<string> permutation(string S){
        vector<string>ans;
        string tmp;
        recu(S,0,ans,tmp);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends