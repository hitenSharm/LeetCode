class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len=0;
        int i=0,j=0;
        unordered_map<char,int>ump;
        while(i<s.size())
        {
            if(j<i)j=i;
            while(j<s.size())
            {
                ump[s[j]]++;
                if(ump.size()>2){
                    ump.erase(s[j]);
                    break;
                }
                j++;
            }
           //cout<<j<<" "<<i<<endl;
            len=max(len,j-i);
            ump[s[i]]--;
            if(ump[s[i]]==0)ump.erase(s[i]);
            i++;
        }
        return len;
    }
};