// https://leetcode.com/problems/battleships-in-a-board

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
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')continue;
                if(i+1<board.size() and board[i+1][j]=='X' and (i-1<0 || i-1>=0 and board[i-1][j]=='.'))ans++;
                if(j+1<board.size() and board[i][j+1]=='X' and (j-1<0 || j-1>=0 and board[i][j-1]=='.'))ans++;
                if(i+1<board.size() and board[i+1][j]!='X' and j+1<board.size() and board[i][j+1]!='X')ans++;
            }
        }
        return ans;
    }
};