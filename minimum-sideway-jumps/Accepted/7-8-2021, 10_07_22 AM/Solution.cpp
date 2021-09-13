// https://leetcode.com/problems/minimum-sideway-jumps

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
    int dp[4][500001];
    int recu(vector<int>& obstacles,int currLane,int index)
    {
        if(index>=obstacles.size()-2)
        return 0;
        if(currLane == obstacles[index]) return 1e6;
        if(dp[currLane][index]!=-1)
        return dp[currLane][index];
        
        int ans=INT_MAX;
        if(index+1<obstacles.size() and obstacles[index+1]!=currLane)
            return dp[currLane][index]=recu(obstacles,currLane,index+1);
        
        return dp[currLane][index]= 1+min(recu(obstacles,((currLane+1)%3 == 0)?3:(currLane+1)%3,index),recu(obstacles,((currLane+2)%3 == 0)?3:(currLane+2)%3,index));        
    }

    int minSideJumps(vector<int>& obstacles) {
        memset(dp,-1,sizeof(dp));
        int ans=recu(obstacles,2,0);
        return ans;
    }
};