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

    int findTime(vector<int>piles, int& h,long long k)
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
        if(piles.size()==1)
        {
            int ans=piles[0]/h + (piles[0] % h !=0);
            return ans;
        }
        sort(piles.begin(),piles.end());
        long long r=1000000000;
        long long l=1;
        int ans=INT_MAX;
        while(l<=r)
        {
            long long m=l+(r-l)/2;
            int tmp=findTime(piles,h,m);            
            if(tmp==-1)
            {
                l=m+1;
            }
            else
            {
                if(m<ans)
                ans=m;
                r=m-1;
            }
        }
        return ans;
    }
};