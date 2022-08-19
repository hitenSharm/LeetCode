class Solution {
public:
    
    unordered_set<int>cols;
    unordered_set<int>rc1;//r-c
    unordered_set<int>rc2;//r+c
    vector<vector<string>>ans;
    
    void recu(vector<string>& board,int r)
    {
        if(r>=board.size()){
            ans.push_back(board);
            return ;
        }
        string& s=board[r];
        for(int i=0;i<board[0].size();i++)
        {
            int& c=i;
            if(cols.find(c)==cols.end() and rc1.find(r-c)==rc1.end() and rc2.find(r+c)==rc2.end())
            {
                cols.insert(c);
                rc1.insert(r-c);
                rc2.insert(r+c);
                s[i]='Q';
                recu(board,r+1);
                cols.erase(c);
                rc1.erase(r-c);
                rc2.erase(r+c);
                s[i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        
        for(int i=0;i<n;i++)
        {
            string s(n,'.');
            board[i]=s;
        }
        recu(board,0);
        return ans;
    }
};