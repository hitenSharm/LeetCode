class Solution {
public:
    int dp[1001];
    static bool compare(string &s1,string &s2)
    {
        return s1.size() < s2.size();
    }
    
    bool canTake(string& s1,string& s2)
    {    
        if(s1.size()==s2.size())return false;
        int ins=0;
        int i=0,j=0;
        int eq=0;
        while(i<s1.size() and ins<=1)
        {
            if(s1[i]==s2[j])
            {
                i++;j++;
                eq++;
            }
            else
            {
                ins++;
                j++;
            }
        }
        ins+=s2.size()-1-j;
        if(eq==s1.size() and ins<=1)return true;
        return false;
    }
    
    int recu(vector<string>& words,int i)
    {
        if(i>=words.size())return 0;
        if(dp[i]!=-1)return dp[i];
        string toCompare=words[i];
        int ans=0;
        for(int j=i+1;j<words.size();++j)
        {
            if(canTake(toCompare,words[j]))
            {                
                ans=max(ans,1+recu(words,j));
            }
        }
        return dp[i]=ans;
    }

    int longestStrChain(vector<string>& words) {
        int ans=0;       
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),compare);
        for(int i=0;i<words.size();++i)
            ans=max(ans,1+recu(words,i));
        return ans;
    }
};