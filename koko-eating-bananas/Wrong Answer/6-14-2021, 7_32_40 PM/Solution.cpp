// https://leetcode.com/problems/koko-eating-bananas

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

    int findTime(vector<int>piles, int& h,int k)
    {
        int ans=0,fl=0;        
        for(int i=0;i<piles.size();i++)
        {
            if(ans>h)
            {
             fl=1;
             break;
            }
            if(piles[i]<=k)
            {
                ans++;
                piles[i]=0;
                continue;
            }
            if(piles[i]>k)
            {                
                int tmp=piles[i]/k + (piles[i] % k !=0);                
                ans+=tmp;
                piles[i]=0;
            }
        }
        if(fl==1 ||ans>h)        
        return -1;
        
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int r=*max_element(piles.begin(),piles.end());
        int l=*min_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int tmp=findTime(piles,h,m);            
            if(tmp==-1)
            {
                l=m+1;
            }
            else
            {
                ans=min(ans,m);
                r=m-1;
            }
        }
        return ans;
    }
};