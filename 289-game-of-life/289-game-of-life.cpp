class Solution {
public:

    void updateConfig(vector<vector<int>>& b, int i, int j)
    {
        int dirs[5] = { -1,0,1,0,-1 };
        int dirs2[5] = { -1,1,1,-1,-1 };
        int l = 0;
        int d = 0;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dirs[k], nj = j + dirs[k + 1];
            if (ni >= 0 and nj >= 0 and ni < b.size() and nj < b[0].size())
            {
                if (b[ni][nj] == 0 || b[ni][nj] == -2)d++;//was dead in old config
                else
                    l++;
            }
            ni = i + dirs2[k];
            nj = j + dirs2[k + 1];
            if (ni >= 0 and nj >= 0 and ni < b.size() and nj < b[0].size())
            {
                if (b[ni][nj] == 0 || b[ni][nj] == -2)d++;
                else
                    l++;
            }
        }
        if (b[i][j] == 1)
        {
            //live checks            
            if (l < 2 || l>3)//dead
                b[i][j] = -1;
            else if (l == 2 || l == 3)
                b[i][j] = 2;     //live                       
        }
        else
        {
            //dead checks
            if (l == 3)b[i][j] = -2;//live
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        //in place update:
        //if its a live cell and it remains live in next update -> 2
        //if its a live cell and it dies in next update -> -1
        //when comparing oc -1,2 => old config had it live
        // if dead and next mein i need to live => -2
        //old config live dead check will just be ki is board i j == 0 =>dead
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                updateConfig(board, i, j);
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {                
                if (board[i][j] == -1)board[i][j] = 0;
                if (board[i][j] == -2 || board[i][j] == 2)board[i][j] = 1;
            }            
        }
    }
};