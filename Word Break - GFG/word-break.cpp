//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings


// A : given string to search
// B : vector of available strings

class Solution
{
public:
    unordered_map<int,bool>dp;
    bool recu(string& a,unordered_set<string>& ust,int index)
    {
        //base case
        if(index>=a.size())return true;
        if(dp.find(index)!=dp.end())return dp[index];
        string temp="";
        bool ans=false;
        while(index<a.size())
        {
            temp+=a[index];
            if(ust.find(temp)!=ust.end())
            {
                //found
                ans = ans || recu(a,ust,index+1);
                //if(ans)return true;
            }
            index++;
        }
        return dp[index]=ans;
    }

    int wordBreak(string a, vector<string> &b) {
        unordered_set<string>ust;
        
        for(auto i:b)ust.insert(i);
        
        return recu(a,ust,0);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends