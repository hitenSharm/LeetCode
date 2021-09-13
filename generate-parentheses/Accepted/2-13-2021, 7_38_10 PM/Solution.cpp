// https://leetcode.com/problems/generate-parentheses

class Solution {
public:

    bool backTrack(vector<string>&ans , string temp, int n, int open,int close,int cnt){
        
        if(temp.length()>=2*n)
        {
            if(cnt==0 )
            {
                ans.push_back(temp);
                return true;
            }
            return false;
        }
        
        if(open<=n)
        {
            cnt++;
            temp=temp+'(';
            backTrack(ans,temp,n,open+1,close,cnt);
            cnt--;
            temp.pop_back();
            
        }
        if(cnt>0 && close<=n)
        {
            cnt--;
            temp=temp+')';
            backTrack(ans,temp,n,open,close+1,cnt);
            cnt++;
            temp.pop_back();
        }
        return false;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        int open=0;
        int close=0;
        int cnt=0;
        backTrack(ans,temp,n,open,close,cnt);
        return ans;
    }
};