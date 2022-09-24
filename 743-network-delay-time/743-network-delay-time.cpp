class Solution {
public:
    typedef pair<int, int> pi;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n + 1, INT_MAX);
        unordered_map<int, vector<pair<int, int>>>adj; //wt,node
        for (int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]].push_back({ times[i][2],times[i][1] });
        }
        priority_queue<pi, vector<pi>, greater<pi>>pq;
        dist[k] = 0;
        pq.push({ 0,k });//wt,node

        while (!pq.empty())
        {
            pi p = pq.top();
            pq.pop();
            int curr = p.second;
            vector<pi>& candidates = adj[curr];
            for (auto i : candidates)
            {
                int newNode = i.second;
                int path = i.first;
                if (dist[newNode] > dist[curr] + path)
                {
                    dist[newNode] = dist[curr] + path;
                    pq.push({ dist[newNode],newNode });
                }
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dist[i]);
        }
        if(ans==INT_MAX)ans=-1;
        return ans;
    }
};