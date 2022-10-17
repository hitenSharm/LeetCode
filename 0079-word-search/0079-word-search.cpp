class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};
    int vis[6][6];
    
    bool dfs(vector<vector<char>>& board, string& word,int idx,int i,int j)
    {
        if(idx>=word.size())return true;
        for(int k=0;k<4;k++)
        {
            int ni=i+dirs[k];
            int nj=j+dirs[k+1];
            if(ni>=0 and ni<board.size() and nj>=0 and nj<board[0].size() and vis[ni][nj]==0 and board[ni][nj]==word[idx])
            {
                vis[ni][nj]=1;
                if(dfs(board,word,idx+1,ni,nj))return true;
                vis[ni][nj]=0;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        memset(vis,sizeof(vis),0);
        bool ans=false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    vis[i][j]=1;
                    ans=ans||dfs(board,word,1,i,j);
                    if(ans)return ans;
                    vis[i][j]=0;
                }
            }
        }
        return ans;
    }
};