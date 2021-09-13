// https://leetcode.com/problems/flip-string-to-monotone-increasing

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
    int minFlipsMonoIncr(string s) {
        int ans=0;
        vector<int>arr(s.length()+1,0);
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='0')
            arr[i]=1+arr[i+1];
            else
            arr[i]=arr[i+1];
        }
        
        for(int i=0;i<s.length();)
        {
            if(s[i]=='0')
            {
                i++;
                continue;
            }
            if(s[i]=='1')
            {
                int zcnt=0,ocnt=0;
                while(i<s.length() and s[i]=='1')
                {
                    ocnt++;
                    i++;
                }
                while(i<s.length() and s[i]=='0')
                {
                    zcnt++;
                    i++;
                }
                if(zcnt>0 and ocnt>0)
                {
                    int prevCnt=arr[i];                    
                    ans+=min(ocnt,zcnt+prevCnt);
                }
            }
        }
        return ans;
    }
};