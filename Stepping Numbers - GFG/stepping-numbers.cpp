//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int getDigits(int m)
    {
        int cnt=0;
        
        while(m>0)
        {
            cnt++;
            m=m/10;
        }
        return cnt;
    }
    
    int recu(int val,int lastDigit,int n,int m,int maxiD,int cd)
    {
        if(cd>maxiD)return 0;
        int ans=0;
        if(val<=m and val>=n)ans++;
        if(lastDigit-1>=0){
            int nval=val*10 + (lastDigit-1);
            ans+=recu(nval,lastDigit-1,n,m,maxiD,cd+1);
        }
        if(lastDigit+1<=9){
            int nval=val*10 + (lastDigit+1);
            ans+=recu(nval,lastDigit+1,n,m,maxiD,cd+1);
        }
        return ans;
    }
    
    int steppingNumbers(int n, int m)
    {
        int digi=getDigits(m);
        
        int val=0;
        int ans=0;
        for(int i=1;i<=9;i++)
        {
            ans+=recu(i,i,n,m,digi,1);//val and lastdigit
        }
        if(0>=n)ans++;
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends