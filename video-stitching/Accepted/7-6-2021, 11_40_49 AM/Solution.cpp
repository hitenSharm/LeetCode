// https://leetcode.com/problems/video-stitching

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
    vector<int>dp;
    
    int recu(vector<vector<int>>& clips,int& t,int index,int en)
    {
        if(en>=t)return 0;
        if(index>=clips.size())
        return 101;
        
        if(dp[en]!=-1)
        return dp[en];
        
        if(clips[index][0]<=en)
        {
            return dp[en]=min(recu(clips,t,index+1,en),1+recu(clips,t,index+1,clips[index][1]));
        }
        else
        return dp[en]=101;
    }
    
    int videoStitching(vector<vector<int>>& clips, int t){
        dp.resize(t+1,-1);
        sort(clips.begin(),clips.end());
        int ans=recu(clips,t,0,0);
        if(ans>=100)
        return -1;
        
        return ans;
    }
};