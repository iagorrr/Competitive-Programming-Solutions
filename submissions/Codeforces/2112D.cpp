#include <bits/stdc++.h>
using namespace std;

/*
 * almost sure it fails in star graph. actually no, this is a no case.
 * */
void solve() {
	int n;
	cin >> n;

	vector<vector<int>> adj(n);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;

		a--, b--;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	
	// find a suitable "root"
	int r = -1;
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 2) {
			r = i;
			break;
		}
	}

	
	if (r < 0) {
		cout << "NO\n";
		return;
	}
	int s = adj[r].back(), t = adj[r].front();

	vector<vector<int>> ans(n);
	vector<int> vis(n);

	ans[s].emplace_back(r);
	ans[r].emplace_back(t);

	vis[s] = vis[t] = vis[r] = 1;

	auto dfs = [&](auto &&self, int u, int p) -> void {
		vis[u] = 1;

		for (auto v : adj[u]) {
			if (v != p and !vis[v]) {
				if (ans[u].size())
					ans[u].emplace_back(v);
				else ans[v].emplace_back(u);

				self(self, v, u);
			}
		}
	};

	dfs(dfs, s, -1);
	dfs(dfs, r, -1);
	dfs(dfs, t, -1);

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (auto j : ans[i]) {
			cout << i + 1 << ' ' << j + 1 << '\n';
		}
	}
}

signed main()  {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;

	while (t--) solve();

}


// AC.
