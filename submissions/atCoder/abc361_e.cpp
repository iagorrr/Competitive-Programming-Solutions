#include <bits/stdc++.h>
using namespace std;

#define int long long

pair<int,int> bfs(int s, const vector<vector<pair<int, int>>>& adj) {
	int u = s, mx = 0;

	using Qt = tuple<int,int,int>;
	queue<Qt> q;
	q.emplace(u, 0, -1);

	while (!q.empty()) {
		auto [v, dv, pv] = q.front();
		q.pop();

		if (dv > mx) mx = dv, u = v;

		for (auto [vv, dvv] : adj[v]) {
			if (vv != pv) {
				q.emplace(vv, dvv + dv, v);
			}
		}
	}

	return {u, mx};
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vector<pair<int, int>>> adj(n);
	int ans = 0;
	for (int i = 0; i < n -1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;

		ans += 2*w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	
	auto [u1, d1] = bfs(0, adj);
	auto [u2, d2] = bfs(u1, adj);

	ans -= d2;

	cout << ans << '\n';
}

// AC, trees, hamiltonian paths, greddy ,diameter
