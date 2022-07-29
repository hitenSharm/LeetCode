class Solution {
public:
    
    unordered_map<char,vector<char>>adjList;
    vector<vector<long long>>dp;
    unordered_map<char,int>ump;
    
    int mod=1000000007;
    
    int recu(char curr,int len,int& n)
    {
        if(len==n)return 1;
        
        if(dp[len][ump[curr]]!=-1)return dp[len][ump[curr]];
        
        vector<char>& candidates=adjList[curr];
        int ans=0;
        for(int i=0;i<candidates.size();i++)
        {
            ans=ans+recu(candidates[i],len+1,n);
            ans%=mod;
        }
        return dp[len][ump[curr]]=ans%mod;
    }
    
    int countVowelPermutation(int n) {     
        dp.resize(n+1,vector<long long>(5,-1));
        adjList['a'].push_back('e');
        adjList['e'].push_back('a');
        adjList['e'].push_back('i');
        adjList['i'].push_back('a');
        adjList['i'].push_back('e');
        adjList['i'].push_back('o');
        adjList['i'].push_back('u');
        adjList['o'].push_back('u');
        adjList['o'].push_back('i');
        adjList['u'].push_back('a');    
        
        string candids="aeiou";
        
        for(int i=0;i<candids.size();i++){
            ump[candids[i]]=i;
        }
        
        int ans=0;
        for(auto i:candids){
            ans+=recu(i,1,n);
            ans%=mod;
        }
        return ans;
    }
};