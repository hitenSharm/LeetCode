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

    int recu(vector<int>& matchsticks,int& sideLen,int currSum,int index,int sides,vector<int>& vis)
    {
       if(sides==4)
       return 0;
       
       if(index>=matchsticks.size())
       return 1;
       
       int ans=1;
       if(currSum==sideLen)
       {
           ans=min(ans,recu(matchsticks,sideLen,0,0,sides+1,vis));
           if(ans==0)
           return 0;
       }
       
       for(int i=index;i<matchsticks.size();i++)
       {
           if(vis[i]==1 || currSum+matchsticks[i]>sideLen)continue;
           vis[i]=1;
           ans=min(ans,recu(matchsticks,sideLen,currSum+matchsticks[i],i+1,sides,vis));
           if(ans==0)
           return 0;
           vis[i]=0;
       }
       return ans;
    }

    bool makesquare(vector<int>& matchsticks) {
        vector<int>vis;
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        for(int i=0;i<matchsticks.size();i++)
        vis.push_back(0);
        
        int sumLen=accumulate(matchsticks.begin(),matchsticks.end(),0);
        int sideLen=sumLen/4;
        
        if(matchsticks.size()<4 || sumLen%4!=0)
        return false;
        
        if(recu(matchsticks,sideLen,0,0,1,vis)==0)
        return true;
        
        return false;
        
    }
};