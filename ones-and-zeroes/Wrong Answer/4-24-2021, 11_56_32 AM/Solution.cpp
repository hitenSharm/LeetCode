// https://leetcode.com/problems/ones-and-zeroes

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    
    int recu(vector<string>& strs , int m, int n,int index, vector<vector<int>>& memo)
    {
        if(index>=strs.size() || m<0 || n<0)
            return 0;   
        if(m==0 && n==0)
            return 1;
    
    if(memo[m][n]!=-1)
    return memo[m][n];
    
    int newm=m;
    int newn=n;
    string s=strs[index];
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        newm--;
        else
        newn--;
    }
        
        return memo[m][n]=max(recu(strs,m,n,index+1,memo),1+recu(strs,newm,newn,index+1,memo));
    }


    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> row(102, -1);
        vector<vector<int>>memo(102,row);
        
        int ans=recu(strs,m,n,0,memo);
        return ans;
    }
};