// https://leetcode.com/problems/decode-ways

class Solution {
public:
    int numDecodings(string s) {
        int dp[s.size()];
        dp[0]=1;
        
        if(s=="0"||s.size()==0)return 0; 
        
        if(s.size()==1)return 1;
        
        string x;
        for(int i=0;i<2;i++)x=x+s[i];        
        int temp=stoi(x);
        if(temp<=26)
        { 
            dp[1]=2;
        }
        else
            dp[1]=1;
        
        for(int i=2;i<s.size();i++)
        {
            if(s[i]=='0')
            { 
                dp[i]=dp[i-1];
                continue;
            }
            string tis;
            for(int j=i-1;j<=i;j++)
                tis=tis+s[j];
             //cout<<tis<<endl;
            int t=stoi(tis);           
            if(t<=26)
            { 
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
                dp[i]=dp[i-1];
        }
        
        return dp[s.size()-1];
        //1,4,2
        //1,4 , 2
        //14 , 2
        
        //1,4,3,5
        
        // 1 , 4 ,3 , 2 , 5
        //14 ,3 , 2 ,5
        
        
        // 1,4,2,3
        // 1 4 2
        // 14,2    3
        // 1,4,2   3
        // 14 , 23
        // 1 4 ,23
        
        
    }
};