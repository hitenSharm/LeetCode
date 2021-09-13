// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int a=g.size();
        int b=s.size();
        int n=min(a,b);
        
        int c=0;
        
        for(int i=0;i<n;i++){
            if(s[i]>=g[i])
                c++;
            else
                break;
        }
        return c;
        
    }
};