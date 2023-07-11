//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int ans=-1;
        int i=0;
        int j=0;
        vector<int>freq(26,0);
        int dist=0;
        while(i<s.size())
        {
            while(j<s.size() and ((freq[s[j]-'a']==0 and dist+1<=k) || freq[s[j]-'a']>0))
            {                
                if(freq[s[j]-'a']==0)dist++;
                freq[s[j]-'a']++;
                j++;
            }
            if(dist==k)
            ans=max(ans,j-i);
            freq[s[i]-'a']--;
            if(freq[s[i]-'a']==0)dist--;
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
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends