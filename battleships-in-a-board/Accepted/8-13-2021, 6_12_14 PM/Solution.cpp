// https://leetcode.com/problems/battleships-in-a-board

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')continue;
                else
                {
                    ans++;
                    board[i][j]='.';
                    int t=i+1;
                    while(t<board.size() and board[t][j]=='X')
                    {
                        board[t][j]='.';
                        t++;
                    }
                    t=j+1;
                    while(t<board[0].size() and board[i][t]=='X')
                    {
                        board[i][t]='.';
                        t++;
                    }
                }
            }
        }
        return ans;
    }
};