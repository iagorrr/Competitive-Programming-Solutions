#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll OO =  1e16;

const int maxn = 400 + 66;
ll adj[maxn][maxn];

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			adj[i][j] = OO;
		}
	}

	int N, M;
	cin >> N >> M;

	vector<tuple<ll,ll,ll>> edges;
	while (M--) {
		ll a, b, c;
		cin >> a >> b >> c;

		a--, b--;
		edges.emplace_back(a,b,c);
		adj[a][b] = min(adj[a][b], c);
	}

	ll ans = 0;

	for (int i = 0; i < N; i++) {
		/*
		for (auto [u, v, c] : edges) {
			if (u <= i and v <= i) {
				adj[u][v] = min(adj[u][v], c);
			}
		}
		*/

		for (int u = 0; u < N; u++) {
			for (int v = 0; v < N; v++) {
				if (adj[u][i] == OO) continue;
				if (adj[i][v] == OO) continue;
				
				adj[u][v] = min(adj[u][v], adj[u][i] + adj[i][v]);
			}
		}

		ll cur = 0;
		for (int u = 0; u < N; u++) {
			for (int v = 0; v < N; v++) {
				if (u == v) continue;
				if (adj[u][v] == OO) continue;
				// cerr << u+1 << ' ' << v+1 << ' ' << adj[u][v] << '\n';
				cur += adj[u][v];
			}
		}
		ans += cur;
	}

	cout << ans << '\n';
}


// AC, graphs, shortest paths, floyd warshall
