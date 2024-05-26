#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1'0'000;
const ll OO = 1'000'000'000;

int N, M;
vector<pair<ll,int>> ADJ[MAXN];

ll dist[2][MAXN];
void dijkstra() {

	using state = tuple<ll, int, int>;
	priority_queue<state, vector<state>, greater<state>> pq;

	dist[0][0] = 0;
	pq.emplace(0, 0, 0);

	while (!pq.empty()) {
		auto [du, qu, u] = pq.top();
		pq.pop();

		if (dist[qu][u] < du)
			continue;
		for (auto [w, v] : ADJ[u]) {
			ll w2 = w + du;
			if (dist[!qu][v] > w2) {
				dist[!qu][v] = w2;
				pq.emplace(w2, !qu, v);
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < MAXN; i++) {
		dist[0][i] = dist[1][i] = OO;
	}

	cin >> N >> M;
	while (M--) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--, v--;
		ADJ[u].emplace_back(w, v);
		ADJ[v].emplace_back(w, u);
	}


	dijkstra();

	cout << (dist[0][N-1] == OO ? -1 : dist[0][N-1]) << '\n';
}

// AC, graphs, dijkstra
