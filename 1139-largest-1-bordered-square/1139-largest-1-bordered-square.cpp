class Solution {
public:

    int loop(vector<vector<int>>& grid,int i,int j)
    {
        int ans=1;
        for(int l=2;l<=grid.size()-i;l++)
        {
            int len=0,fl=0;
            int ti=i,tj=j;
            int ti2=i,tj2=j;
            while(len!=l)
            {
                if(ti+l-1<grid.size() and tj2+l-1<grid[0].size() and grid[ti][tj]==1 and grid[ti+l-1][tj]==1 and grid[ti2][tj2]==1 and grid[ti2][tj2+l-1]==1)
                {
                    len++;
                    tj++;ti2++;
                }
                else
                {
                    fl=1;
                    break;
                }
            }
            if(fl==1)continue;
            ans=max(ans,l*l);
            
        }
        return ans;
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)ans=max(ans,loop(grid,i,j));
            }
        }
        return ans;
    }
};