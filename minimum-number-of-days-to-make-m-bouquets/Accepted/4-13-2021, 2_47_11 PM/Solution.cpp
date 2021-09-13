// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
        
    int tempDays(vector<int>& bloomDay, int m, int k,int days)
    {
        int tempAns;
        int bsets=0;
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bsets==m)
            break;
            
            if(bloomDay[i]<=days)
            {
                cnt++;
                if(cnt>=k)
                {
                    cnt=0;
                    bsets++;
                    continue;
                }
            }
            else
            {
                if(cnt>=k)
                {
                    bsets++;
                }
                cnt=0;
            }
        }
        if(cnt>=k)
         {
             bsets++;
         }
        if(bsets<m)
        return -1;
        else
        return bsets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
      int maxi=bloomDay[0]; 
      int mini=bloomDay[0];
        if(m*k >bloomDay.size())
            return -1;
      for(int i=0;i<bloomDay.size();i++)
      {
          maxi=max(maxi,bloomDay[i]);          
          mini=min(mini,bloomDay[i]);
      }
      int l=mini;
      int r=maxi;
      
      while(l<r)
      {
          int mid=l + (r - l) / 2;
          
          int temp=tempDays(bloomDay,m,k,mid);          
          if(temp==-1)
          {
              l=mid+1;
          }
          else
          {
              r=mid;
          }
      }
      
      return l;
      
    }
};