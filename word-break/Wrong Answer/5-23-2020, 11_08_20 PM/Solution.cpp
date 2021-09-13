// https://leetcode.com/problems/word-break

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)
        {
            if(s.find(wordDict[i])!=string::npos)
                continue;
            else
                return false;
        }
        return true;
    }
};