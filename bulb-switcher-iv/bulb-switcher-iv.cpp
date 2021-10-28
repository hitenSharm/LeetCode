class Solution {
public:
    int minFlips(string target) {
        int state=0;
        int ans=0;
        for(int i=0;i<target.length();i++)
        {
            if(state==target[i]-'0')continue;            
            else
            {
                ans++;
                state=(state==0?1:0);                
            }
        }
        return ans;
    }
};