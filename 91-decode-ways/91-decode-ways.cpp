class Solution {
public:
    unordered_set<string>ust;
    vector<int>dp;
    int recu(int index,string& s)
    {
        if(index>=s.size())
        {            
            return 1;
        }   
        if(dp[index]!=-1)return dp[index];
        string temp="";
        int ans=0;
        int currIndex=index;
        while(index<s.size())
        {
            temp+=s[index];
            if(ust.find(temp)==ust.end())break ;
            ans+=recu(index+1,s);
            index++;
        }    
        return dp[currIndex]=ans;    
    }

    int numDecodings(string s) {        
        dp.resize(s.size(),-1);
        for(int i=1;i<=26;i++)
        {
            ust.insert(to_string(i));
        }        
        return recu(0,s);
    }
};