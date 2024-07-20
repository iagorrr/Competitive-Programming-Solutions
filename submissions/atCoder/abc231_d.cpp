#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;


	vector<vector<int>> adj(n);
	vector<int> dg(n);

	for (int i = 0, a,b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		dg[a]++;
		dg[b]++;
		if (dg[a] > 2 or dg[b] > 2) {
			cout << "No\n";
			return 0;
		}

		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	vector<int> vis(n);
	auto dfs = [&](auto&& self, int u, int p) -> int {
		vis[u] = true;
		for (auto v : adj[u]) {
			if (vis[v] and v != p) return -1000;
			else if (!vis[v])
				return self(self, v, u) + 1;
		}
		return 0;
	};


	int depth = 0;
	for (int i = 0; i < n; i++) {
		if (dg[i] == 1 and !vis[i])
			depth += dfs(dfs, i, -1);
	}

	if ( depth == m) {
		cout << "Yes\n";
	}
	else cout << "No\n";

}


// AC, graphs, dfs/bfs, cycles
