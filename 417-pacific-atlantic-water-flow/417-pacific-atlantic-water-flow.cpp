class Solution {
public:

    vector<vector<int>> bfs(int i, int j, vector<vector<int>>& ht)
    {
        queue<pair<int, int>>q;
        vector<vector<int>> ans(ht.size(),vector<int>(ht[0].size(),-1));
        if (i == 0 and j == 0)
        {
            for (int k = 0; k < ht.size(); k++)
            {
                q.push({ k,0 });
                ans[k][0] = 1;
            }
            for (int k = 0; k < ht[0].size(); k++)
            {
                q.push({ 0,k });
                ans[0][k] = 1;
            }
        }
        else
        {
            for (int k = i; k >=0; k--)
            {
                q.push({ k,j });
                ans[k][j] = 1;
            }
            for (int k = j; k >= 0; k--)
            {
                q.push({ i,k });
                ans[i][k] = 1;
            }
        }
        int dirs[5] = { -1,0,1,0,-1 };
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int ni = p.first + dirs[k], nj = p.second + dirs[k + 1];
                if (ni < 0 || nj < 0 || ni >= ht.size() || nj >= ht[0].size() || ans[ni][nj] != -1)continue;
                if (ht[ni][nj] >= ht[p.first][p.second]) {
                    q.push({ ni,nj });
                    ans[ni][nj] = 1;
                }
            }
        }
        return ans;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> pf = bfs(0, 0, heights);
        int n = heights.size() - 1,m=heights[0].size()-1;
        vector<vector<int>> atl = bfs(n, m, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = 0; j < pf[0].size(); j++)
            {
                if (pf[i][j] == 1 and atl[i][j] == 1)ans.push_back({ i,j });
            }
        }
        return ans;
    }
};