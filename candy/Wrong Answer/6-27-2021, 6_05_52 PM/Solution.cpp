// https://leetcode.com/problems/candy

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
    int candy(vector<int>& ratings) {
        int ans=0;
        int st=1;
        for(int i=0;i<ratings.size();)
        {
            int len=0,ansMinus=0,fl=0;
            while(i+1 < ratings.size() and ratings[i+1]<=ratings[i])
            {
                ansMinus+=st;
                len++;
                i++;
                st--;
                fl=1;
            }
            if(fl==1)
            {
                ansMinus+=st;
                len++;
                i++;                
                fl=0;
                if(st>=1)
                {
                    ans+=ansMinus;
                    if(i==ratings.size())break;
                }
                if(st<1)
                {                    
                    int diff=1-st;
                    st=1;                
                    ans=ans+(ansMinus+(diff*len));                      
                    if(i==ratings.size())break;
                }
            }            
            
            while(i+1<ratings.size() and ratings[i+1]>ratings[i])
            {
                ans+=st;
                st++;i++;
            }
            if(i+1==ratings.size())
            {    
                if(ratings[i-1]<ratings[i])
                st++;
                ans+=st;
                break;
            }
        }
        return ans;
    }
};