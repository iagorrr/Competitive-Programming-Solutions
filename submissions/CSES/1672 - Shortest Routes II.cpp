#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	int N , M, Q;
	cin >> N >> M >> Q;

	const ll oo = 1e15;
	vector<vector<ll>> dist(N, vector<ll>(N,oo));

	for (int i = 0, a, b, c; i < M; i++) {
		cin >> a >> b >> c;
		a--, b--;

		dist[a][b] = min(dist[a][b], (ll)c);
		dist[b][a] = min(dist[b][a], (ll)c);
	}

	for (int i = 0; i < N; i++) dist[i][i] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (dist[j][i] != oo and dist[i][k] != oo)
					dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	while (Q--) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		cout << (dist[u][v] < oo ? dist[u][v] : -1) << '\n';


	}
}
