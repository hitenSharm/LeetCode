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

    int recu(vector<int>& obstacles,int index,int currLane)
    {
        if(index==obstacles.size()-1)
        return 0;
        
        while(index+1<obstacles.size() and obstacles[index+1]!=currLane)
        {
            return recu(obstacles,index+1,currLane);
        }
        int candidates[3]={1,2,3};
        int ans=INT_MAX;
        for(int i=0;i<3;i++)
        {
            if(obstacles[index]!=candidates[i] and candidates[i]!=currLane)
            ans=min(ans,1+recu(obstacles,index+1,candidates[i]));
        }
        return ans;
    }

    int minSideJumps(vector<int>& obstacles) {
        int ans=recu(obstacles,0,2);
        return ans;
    }
};