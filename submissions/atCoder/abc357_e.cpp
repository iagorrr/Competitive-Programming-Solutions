#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<int> nxt(n);
	for (auto &x : nxt) 
		cin >> x, x--;

	vector<int>  vis(n), rs(n), in(n), fs(n), ds(n);
	auto dfs = [&](auto&& self, int u, int d = 0) -> void {
		vis[u] = 1;
		ds[u] = d;

		auto v = nxt[u];
		switch (vis[v]) {
			case 0:
				self(self, v, d + 1);
				if (in[v] and fs[v] != v)
					in[u] = 1, fs[u] = fs[v], rs[u] = rs[v];
				else rs[u] = rs[v] + 1;
				break;
			case 1:
				in[u] = 1;
				fs[u] = v;
				rs[u] = ds[u] - ds[v] + 1;
				break;
			case 2:
				rs[u] = rs[v] + 1;
				break;
		}


		vis[u] = 2;

	};



	long long ans = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) dfs(dfs, i);
		ans += rs[i];
	}

	cout << ans << '\n';
	
}

// AC, graphs, dfs, functional graph
