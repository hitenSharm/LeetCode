// https://leetcode.com/problems/path-with-minimum-effort

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
     int m = heights.size(), n = heights[0].size();
     int dirs[5] = {-1, 0, 1, 0, -1};

    vector<vector<int>> nodes(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

    heap.emplace(0, 0);
    while (!heap.empty()) {
      int effort = heap.top().first;
      int x = heap.top().second / 100, y = heap.top().second % 100;
      heap.pop();

      if (x == m - 1 && y == n - 1) return effort;
      if (effort >= nodes[x][y]) continue;
      nodes[x][y] = effort;

      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i], ny = y + dirs[i + 1];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
        heap.emplace(n_effort, nx * 100 + ny);
      }
    }
    return -1;
    }
};