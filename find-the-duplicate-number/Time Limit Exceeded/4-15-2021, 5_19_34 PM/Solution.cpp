// https://leetcode.com/problems/find-the-duplicate-number

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int l=1;
        int hi=a.size()-1;
        
        while(l<hi)
        {
            int mid=(l+(hi-l))/2;
            int cnt=0;
            for(int i=0;i<a.size();i++)
            {
                if(a[i]<=mid)
                cnt++;
            }
            if(cnt>mid)
            hi=mid;
            else
            l=mid+1;
        }
        return l;
        
    }
};