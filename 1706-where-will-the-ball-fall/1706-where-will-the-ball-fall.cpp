class Solution {
public:

    int solve(vector<vector<int>>& grid,int j)
    {
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][j]==1)
            {
                if(j+1>=grid[0].size())return -1;
                if(grid[i][j+1]==-1)return -1;
                j++;
            }
            else
            {
               if(j-1<0)return -1;
               if(grid[i][j-1]==1)return -1; 
               j--;
            }
        }
        return j;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        for(int i=0;i<grid[0].size();i++)
        {
            ans.push_back(solve(grid,i));
        }
        return ans;
    }
};