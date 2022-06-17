#pragma GCC optimize("Ofast")# pragma GCC target("avx,avx2,fma")
static auto _ =[]()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}();
class Solution
{
	public:
		int dirs[5] = { 1, 0, -1, 0, 1 };
	int nearestExit(vector<vector < char>> &maze, vector< int > &entrance)
	{
		queue<pair<int, int>> q;
		q.push({ entrance[0], entrance[1] });
		maze[entrance[0]][entrance[1]] = '+';
		int steps = 0;
		while (!q.empty())
		{
			int len = q.size();
			for (int i = 0; i < len; ++i)
			{
				pair<int, int> &p = q.front();
				int r = p.first, c = p.second;
				for (int k = 0; k < 4; ++k)
				{
					int nr = r + dirs[k], nc = c + dirs[k + 1];
					if (nr >= 0 and nc >= 0 and nr < maze.size() and nc < maze[0].size() and maze[nr][nc] == '.')
					{
						if (nr == 0 || nc == 0 || nr == maze.size() - 1 || nc == maze[0].size() - 1)
						{
							return steps + 1;
						}

						maze[nr][nc] = '+';
						q.push({ nr, nc });
					}
				}

				q.pop();
			}

			steps++;
		}

		return -1;
	}
};