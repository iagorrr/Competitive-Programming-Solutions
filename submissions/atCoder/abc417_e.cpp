#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;

	x--, y--;

	vector<vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		u--, v--;

		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	vector<int> found(n);
	vector<vector<int>> lex(n);

	found[x] = 1;
	lex[x] = {x};

	using t = pair<vector<int>, int>;
	priority_queue<t, vector<t>, greater<>> pq;

	pq.emplace(lex[x], x);

	vector<int> inpu(n);
	while (pq.size()) {
		auto [pu, u] = pq.top();
		pq.pop();


		if (lex[u] < pu) continue;


		for (auto pui : pu) inpu[pui] = 1;

		for (auto v : adj[u]) {
			if (!inpu[v]) {
				vector<int> cur = lex[u];
				cur.emplace_back(v);
				if (!found[v] or lex[v] > cur) {
					found[v] = 1;
					lex[v] = cur;
					pq.emplace(cur, v);
				}

			}
		}

		for (auto pui : pu) inpu[pui] = 0;
	}

	auto ans = lex[y];

	for (auto ai : ans) cout << ai + 1 << ' ';
	cout << '\n';;
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));

	int t;
	cin >>t;

	while(t--) solve();
}
// AC, shortest paths
