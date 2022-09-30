class Solution {
public:
    vector<int>ans;

    void dfs(int node, unordered_map<int, vector<int>>& g)
    {
        ans.push_back(node);
        vector<int>& candi = g[node];
        for (auto i : candi)
        {
            dfs(i, g);
        }
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        //o(n2) approach is obv
        unordered_map<int, vector<int>>graph;
        for (int i = 0; i < pid.size(); i++)
        {
            graph[ppid[i]].push_back(pid[i]);
        }
        
        dfs(kill, graph);
        return ans;
    }
};