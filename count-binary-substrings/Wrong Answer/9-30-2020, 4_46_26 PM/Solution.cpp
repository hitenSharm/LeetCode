// https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        queue<char>q;
        q.push(s[0]);
        for(int i=1;i<s.length();i++)
        { 
            char x=q.front();
            if(s[i]=='1'&&x=='0')
            { 
                ans++;
                q.pop();
                q.push(s[i]);
                continue;
            }
            if(s[i]=='0'&&x=='1')
            { 
                ans++;
                q.pop();
                q.push(s[i]);
                continue;
            }
            q.push(s[i]);
        }
        return ans;
    }
};