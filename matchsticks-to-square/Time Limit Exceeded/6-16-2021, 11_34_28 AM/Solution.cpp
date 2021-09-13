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

    int recu(vector<int>& matchsticks,int& sideLen,int currSum,int index,int sides,vector<int>vis)
    {
       if(sides==4)
       return 0;
       
       if(index>=matchsticks.size() || currSum + matchsticks[index]>sideLen)
       return 1;
       
       int ans1=1;
       if(currSum+matchsticks[index]==sideLen)
       {
            for(int i=0;i<matchsticks.size();i++)
            {
                if(vis[i]==1)continue;
                vis[i]=1;
                ans1=min(ans1,recu(matchsticks,sideLen,0,i,sides+1,vis));
                vis[i]=0;
            }
       }
       for(int i=0;i<matchsticks.size();i++)
        {
            if(vis[i]==1)continue;
            vis[i]=1;
            ans1=min(ans1,recu(matchsticks,sideLen,currSum+matchsticks[i],i,sides,vis));
            vis[i]=0;
        }
       return ans1;
    }

    bool makesquare(vector<int>& matchsticks) {
        vector<int>vis;
        for(int i=0;i<matchsticks.size();i++)
        vis.push_back(0);
        int sumLen=accumulate(matchsticks.begin(),matchsticks.end(),0);
        int sideLen=sumLen/4;
        if(matchsticks.size()<4 || sumLen%4!=0)
        return false;
        int sol=recu(matchsticks,sideLen,0,0,1,vis);
        if(sol==0)
        return true;
        
        return false;
        
    }
};