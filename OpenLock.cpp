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

    vector < string > generateCandidates(string current) {
      vector < string > send;
      for (int i = 0; i < 4; i++) {
        string temp = current;
        temp[i] = (current[i] - '0' + 1) % 10 + '0';
        send.push_back(temp);
        temp[i] = (current[i] - '0' - 1 + 10) % 10 + '0';
        send.push_back(temp);
      }
      return send;
    }

  int openLock(vector < string > & deadends, string target) {
    unordered_map < string, int > ump;
    for (int i = 0; i < deadends.size(); i++)
      ump[deadends[i]]++;
    string sol = "0000";
    if (sol == target) return 0;
    unordered_map < string, int > vis;
    queue < string > bfs;
    bfs.push(sol);
    vis[sol] = 1;
    if (ump.find(sol) != ump.end()) return -1;
    int ans = 0;

    while (!bfs.empty()) {
      int toExplore = bfs.size();
      for (int i = 0; i < toExplore; i++) {
        string curr = bfs.front();
        bfs.pop();
        vector < string > candidates = generateCandidates(curr);
        for (auto i: candidates) {
          if (i == target) return ++ans;
          if (vis.find(i) != vis.end()) continue;
          if (ump.find(i) == ump.end()) {
            bfs.push(i);
            vis[i] = 1;
          }
        }
      }
      ans++;
    }
    return -1;

  }
};