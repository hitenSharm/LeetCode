// https://leetcode.com/problems/maximum-length-of-pair-chain

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
    }

    int recu(int index,vector<int> &dp,vector<vector<int>>& pairs,int prevValue)
    {
        if(index>=pairs.size())
        return 0;
        
        if(dp[index]!=-1)
        return dp[index];
        
        int take=0;
        
        if(pairs[index][0]>prevValue){
            take=1+recu(index+1,dp,pairs,pairs[index][1]);
        }
        int cantTake=0;
        
        cantTake=recu(index+1,dp,pairs,prevValue);
        
        return dp[index]=max(cantTake,take);
        
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        vector<int>dp(1001,-1);
        int ans;
        ans=recu(0,dp,pairs,-1002);
        return ans;
    }
};