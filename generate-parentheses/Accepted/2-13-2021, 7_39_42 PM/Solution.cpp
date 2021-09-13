// https://leetcode.com/problems/generate-parentheses

class Solution {
public:

    bool backTrack(vector<string>&ans , string temp, int n, int open,int close){
        
        if(temp.length()>=2*n)
        {
            if(open==close)
            {
                ans.push_back(temp);
                return true;
            }
            return false;
        }
        
        if(open<=n)
        {            
            temp=temp+'(';
            backTrack(ans,temp,n,open+1,close);           
            temp.pop_back();            
        }
        if(open>close&&close<=n)
        {            
            temp=temp+')';
            backTrack(ans,temp,n,open,close+1);            
            temp.pop_back();
        }
        return false;
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        int open=0;
        int close=0;
        
        backTrack(ans,temp,n,open,close);
        return ans;
    }
};