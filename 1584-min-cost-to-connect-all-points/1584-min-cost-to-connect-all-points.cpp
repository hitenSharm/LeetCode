class Solution {
public:
    typedef pair<int, int> pi;

    int getDist(int x, int y, vector<vector<int>>& points)
    {
        int ans = abs((points[x][0] - points[y][0])) + abs((points[x][1] - points[y][1]));
        return ans;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        //prims
        vector<int>dist(points.size(), INT_MAX);
        dist[0] = 0;
        vector<int>vis(points.size(), 0);
        priority_queue<pi, vector<pi>, greater<pi>>pq;//min heap
        pq.push({ 0,0 });
        while (!pq.empty())
        {
            pi p = pq.top();
            pq.pop();
            int node = p.second;
            if (vis[node] == 1)continue;
            vis[node] = 1;
            for (int i = 0; i < points.size(); i++)
            {
                if (vis[i] == 1)continue;
                int d = getDist(i, node, points);
                if (dist[i] > d) {
                    dist[i] = d;
                    pq.push({ d,i });
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < dist.size(); i++)ans += dist[i];
        return ans;
    }
};