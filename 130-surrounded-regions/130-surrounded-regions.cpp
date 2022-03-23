#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    
    int dirs[5]={1,0,-1,0,1};
    
    void recu(vector<vector<char>>& board,int i,int j)
    {
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!='O')return;
        board[i][j]='V';
        for(int k=0;k<4;k++)
        {            
            recu(board,i+dirs[k],j+dirs[k+1]);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][0]=='O')recu(board,i,0);
            if(board[i][board[0].size()-1]=='O')recu(board,i,board[0].size()-1);
        }
        for(int j=0;j<board[0].size();j++)
        {
            if(board[0][j]=='O')recu(board,0,j);
            if(board[board.size()-1][j]=='O')recu(board,board.size()-1,j);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='V')
                board[i][j]='O';
                else
                board[i][j]='X';
            }
        }
    }
};