class Solution {
public:
    unordered_map<int, vector<int>>adj;
    unordered_set<int>vis;
    vector<int>ans;

    bool dfs(int node, vector<int>& recu)
    {
        vis.insert(node);
        vector<int>& candi = adj[node];
        for (auto i : candi)
        {
            if (recu[i] == 1)return false;
            if (vis.find(i) != vis.end())continue;
            recu[i] = 1;
            bool ans = dfs(i, recu);
            if(!ans)return false;
            recu[i] = 0;
        }
        ans.push_back(node);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        for (auto i : pre)
        {
            adj[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (vis.find(i) != vis.end())continue;
            vector<int>recu(numCourses,0);
            recu[i]=1;
            bool fl = dfs(i, recu);
            if (!fl)return {};
        }

        return ans;
    }
};