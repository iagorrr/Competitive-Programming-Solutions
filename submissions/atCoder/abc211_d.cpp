#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1'000'000'000 + 7;

const int maxn = 2 * 1'00'000;
vector<int> adj[maxn];
ll ways[maxn];
int vis[maxn];

auto run() {
	int n, m;
	cin >> n >> m;

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	for (int i = 0; i < n; i++) {
		vis[i] = 4*n;
	}

	queue<int> q;

	ways[0] = 1;
	vis[0] = 0;
	q.push(0);

	while (!q.empty()) {
		auto u = q.front();
		q.pop();

		int du = vis[u];

		for (auto v : adj[u]) {
			if (vis[v] >= du +1)
				ways[v] = (ways[v] + ways[u]) % mod;

			if (vis[v] > du + 1){
			       	q.push(v);
				vis[v] = du + 1;
			}
		}

	}

	cout << ways[n -1] << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, graphs, dfs/bfs

