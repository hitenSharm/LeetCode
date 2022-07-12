class Solution {
public:
    int romanToInt(string s) {
            unordered_map<char, int> ump = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
        int ans=ump[s[s.size()-1]];
        for(int i=s.size()-2;i>=0;i--)
        {
            if(ump[s[i]]<ump[s[i+1]])ans-=ump[s[i]];
            else
            ans+=ump[s[i]];
        }
        return ans;
    }
};