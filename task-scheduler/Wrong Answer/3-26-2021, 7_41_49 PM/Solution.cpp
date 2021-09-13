// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        int maxCnt=0;
        char isMax;
        for(char i : tasks)
        {
            mp[i]++;
            if(maxCnt<mp[i])
            {
                maxCnt=mp[i];
                isMax=i;
            }
        }
        int minLen=maxCnt+(maxCnt-1)*n;
        int spaces;
        if(n>0)
            spaces=maxCnt-1;
        else
            spaces=0;
        for(auto it:mp)
        {
            if(it.second>maxCnt-1 && it.first!=isMax)
                minLen=minLen+it.second-spaces;
        }
        return minLen;
    }
};