// https://leetcode.com/problems/number-of-good-ways-to-split-a-string

class Solution {
public:
    int numSplits(string s) {
        int siz=s.length();
        int freqS[siz];
        int freqE[siz];
        map<char,int>mp;
        int in=0;
        int uniq=0;
        for(char i :s)
        {
            if(mp.find(i)==mp.end())
            {
                mp[i]=1;
                uniq++;
            }
            freqS[in]=uniq;
            in++;
        }
        mp.clear();
        uniq=0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]=1;
                uniq++;
            }
            freqE[i]=uniq;            
        }
        int cnt=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(freqS[i]==freqE[i+1])
                cnt++;
        }
        return cnt;
    }
};