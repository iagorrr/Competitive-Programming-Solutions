#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(int source, int sink, vector<vector<int>>& adj) {
	const int n = adj.size();

	queue <int> q;
	vector<ll> vis(n, -1);

	q.push(source);
	vis[source] = 0;

	while (q.size()) {
		int u = q.front();
		q.pop();

		for (auto v : adj[u]) {
			if (u == source and v == sink) continue;
			if (vis[v] != -1) continue;

			vis[v] = vis[u] + 1;
			q.push(v);
		}
	}

	return vis[sink] == -1 ? LLONG_MAX : vis[sink] + 1;
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<pair<int,int>> edges(m);

	for (auto& [u, v] : edges) {
		cin >> u >> v;
		u--, v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<ll> ans(n, LLONG_MAX);
	for (auto &[u, v] : edges) {
		ll s = solve(u, v, adj);
		ans[u] = min(ans[u], s);
		ans[v] = min(ans[v], s);
	}


	ll ret = 0;
	for (int i = 0; i < n; i++) {
		ll v = ans[i] == LLONG_MAX ? 1 : ans[i];
		ret += (v * (i+1));
	}

	cout << ret << '\n';
}

// AC, dfs & bfs related
