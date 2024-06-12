#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3'00'000;
vector<int> adj[MAXN];
int tin[MAXN], last[MAXN], timer;

void dfs(int u) {
	tin[u] = timer++;

	for (auto v : adj[u]) dfs(v);

	last[u] = timer-1;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	memset(tin, -1, sizeof tin);
	memset(last, -1, sizeof last);
	int n, q;
	cin >> n >> q;

	for (int i = 1, p; i < n; i++) {
		cin >> p;
		adj[p-1].emplace_back(i);
	}

	dfs(0);

	while (q--) {
		int m;
		cin >> m;
		vector<int> xs(m);
		for (auto &xi :xs) {
			cin >> xi;
			xi--;
		}

		sort(xs.begin(), xs.end(), [&](int a, int b) {
				return tin[a] < tin[b];
		});

		int ans = 1;
		for (int i  = 0; i + 1 < m; i++) {
			ans += tin[xs[i+1]] > last[xs[i]];
		}


		cout << ans << '\n';
	}
	
}


// AC, greddy, trees
