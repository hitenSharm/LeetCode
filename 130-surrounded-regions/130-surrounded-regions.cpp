class Solution {
public:
    
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        int dirs[5]={-1,0,1,0,-1};
        board[i][j]='@';
        for(int k=0;k<4;k++)
        {
            int ni=i+dirs[k],nj=j+dirs[k+1];
            if(ni>=0 and nj>=0 and ni<board.size() and nj<board[0].size() and board[ni][nj]=='O')
                dfs(board,ni,nj);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        //start from the edges instead of the normal
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0);
            if(board[i][board[0].size()-1]=='O')
                dfs(board,i,board[0].size()-1);
        }
        for(int j=0;j<board[0].size()-1;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j);
            if(board[board.size()-1][j]=='O')
                dfs(board,board.size()-1,j);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='@')board[i][j]='O';
                else
                    board[i][j]='X';
            }
        }
    }
};