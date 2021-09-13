// https://leetcode.com/problems/count-binary-substrings

#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
static auto _ = [] ()
{ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr=1,prev=0,ans=0;
        for(int i=1;i<s.length();i++)
        {
           if(s[i]==s[i-1])
           curr++;
           else
           {
            ans+=min(prev,curr);
            prev=curr;
            curr=1;
           }
        }
        return (ans+min(prev,curr));
    }
};