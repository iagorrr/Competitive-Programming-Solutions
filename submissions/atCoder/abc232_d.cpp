#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int h, w;
	cin >> h >> w;

	vector<string> grid(h);
	for (auto &i : grid)
		cin >> i;

	using st = tuple<int,int,int>;
	vector<vector<int>> vis(h, vector<int>(w));
	queue<st> q;
	q.emplace(0,0,1);
	vis[0][0] = 1;

	int ans = 0;
	while (!q.empty()) {
		auto [x, y, d] = q.front();
		q.pop();

		ans = max(ans, d);

		if (x + 1 < h and grid[x+1][y] != '#' and !vis[x+1][y]) {
			q.emplace(x+1, y, d + 1);
			vis[x+1][y] = 1;
		}


		if (y + 1 < w and grid[x][y+1] != '#' and !vis[x][y+1]) {
			q.emplace(x, y+1, d + 1);
			vis[x][y+1] = 1;
		}

	}

	cout << ans << '\n';
}

// AC, graphs, bfs/dfs
