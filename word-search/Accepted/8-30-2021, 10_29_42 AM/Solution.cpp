// https://leetcode.com/problems/word-search

class Solution {
public:

    int vis[6][6];
    int dirs[5] = {-1, 0, 1, 0, -1};
    
    bool recu(vector<vector<char>>& board,int i,int j,string& word,int len)
    {
        if(len==word.size())return true;
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int newI=i+dirs[k],newJ=j+dirs[k+1];
            
            if(newI>=0 and newI<board.size() and newJ>=0 and newJ<board[0].size() and vis[newI][newJ]==-1 and board[newI][newJ]==word[len])
            {
                vis[newI][newJ]=1;
                ans=ans||recu(board,newI,newJ,word,len+1);
                if(ans)return true;
                vis[newI][newJ]=-1;
            }
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        memset(vis,-1,sizeof(vis));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    vis[i][j]=1;
                    if(recu(board,i,j,word,1))return true;
                    vis[i][j]=-1;
                }
            }
        }
        return false;
    }
};