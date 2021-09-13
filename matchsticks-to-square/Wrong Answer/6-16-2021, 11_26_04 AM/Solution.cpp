// https://leetcode.com/problems/matchsticks-to-square

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

    int recu(vector<int>& matchsticks,int& sideLen,int currSum,int index,int sides)
    {
       if(sides==4)
       return 0;
       
       if(index>=matchsticks.size() || currSum + matchsticks[index]>sideLen)
       return 1;
       
       int ans1=1;
       if(currSum+matchsticks[index]==sideLen)
       {
            ans1=min(ans1,recu(matchsticks,sideLen,0,index+1,sides+1));
       }
       ans1=min(ans1,recu(matchsticks,sideLen,currSum+matchsticks[index],index+1,sides));
       return ans1;
    }

    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end());
        int sumLen=accumulate(matchsticks.begin(),matchsticks.end(),0);
        int sideLen=sumLen/4;
        if(matchsticks.size()<4 || sumLen%4!=0)
        return false;
        int sol=recu(matchsticks,sideLen,0,0,1);
        if(sol==0)
        return true;
        
        return false;
        
    }
};