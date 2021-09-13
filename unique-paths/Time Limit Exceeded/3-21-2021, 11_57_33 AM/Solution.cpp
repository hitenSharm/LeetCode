// https://leetcode.com/problems/unique-paths

class Solution {
public:
    
    void dfs(int x,int y, int tarx,int tary, int& cnt){
        
        if(x>tarx||y>tary)
            return ;
        
        if(x==tarx&&y==tary)
        {
            cnt=cnt+1;
            return ;
        }
        dfs(x+1,y,tarx,tary,cnt);
        dfs(x,y+1,tarx,tary,cnt);
    }
    
    int uniquePaths(int m, int n) {
        int cnt=0;
        int x=0;
        int y=0;
        int targetX=n-1;
        int targetY=m-1;
        dfs(x,y,targetX,targetY,cnt);
        return cnt;
    }
};