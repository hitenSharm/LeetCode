// https://leetcode.com/problems/task-scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int>mp;
        int maxCnt=0;        
        for(char i : tasks)
        {
            mp[i]++;
            if(maxCnt<mp[i])
            {
                maxCnt=mp[i];                
            }
        }
        int charCnt=0;
        for(auto it:mp)
        {
            if(it.second==maxCnt)
                charCnt++;
        }
        int occupied=charCnt*maxCnt;
        int spaces=(n*(maxCnt-1))-(charCnt-1)*(maxCnt-1);
        int extras=tasks.size()-occupied;
        int idles=max(0,spaces-extras);
        
        return tasks.size()+idles;
        
    }
};