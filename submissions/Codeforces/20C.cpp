#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
const int MAXN = 1'00'000;
const ll MAXW = 1'000'000ll;
constexpr ll OO = MAXW * MAXN + 1;
using Edge = pair<ll, int>; // { weigth, node}
using Adj = vector<vector<Edge>>;

pair<vector<ll>, vi> dijkstra(const Adj &g, int s) {
	int n = g.size();
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	vll ds(n, OO);
	vi ps(n, -1);
	pq.emplace(0, s);
	ds[s] = 0;
	while (!pq.empty()) {
		auto [du, u] = pq.top(); pq.pop();
		if (ds[u] < du)
			continue;

		for (auto [w, v] : g[u]) {
			ll ndv = du + w;
			if (ds[v] > ndv) {
				ds[v] = ndv;
				ps[v] = u;
				pq.emplace(ndv, v);
			}
		}
	}

	return {ds, ps};
}

// optional !
vi recover_path(int source, int ending, const vi &ps) {
	if (ps[ending] == -1) return {};
	int cur = ending;
	vi ans;
	while (cur != -1) {
		ans.emplace_back(cur);
		cur = ps[cur];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	Adj g(n);
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		u--,v--;
		g[u].emplace_back(w, v);
		g[v].emplace_back(w, u);
	}

	auto [_, ps] = dijkstra(g, 0);

	auto ans = recover_path(0, n-1, ps);
	if (ans.empty()) {
		cout << -1 << '\n';
		return 0;
	}
	for (auto i : ans) {
		cout << i + 1 << ' ';
	}
	cout << '\n';

}

// AC, graphs, shortest paths, dijkstra
