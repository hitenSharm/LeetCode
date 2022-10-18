class Solution {
public:
    
    string conv(string& temp)
    {
        string ans="";
        int i=0,j=0;
        while(i<temp.size())
        {
            j=i;
            char curr=temp[i];
            int cnt=0;
            while(j<temp.size() and temp[j]==curr)
            {
                cnt++;
                j++;
            }
            ans+=to_string(cnt)+temp[i];
            i=j;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        string temp=to_string(1);
        if(n==1)return temp;
        for(int i=2;i<=n;i++)
        {
            temp=conv(temp);                  
        }
        return temp;
    }
};