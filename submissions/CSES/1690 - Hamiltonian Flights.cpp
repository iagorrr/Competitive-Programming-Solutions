#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1'000'000'007;
 
const int MAXN = 20;
int memo[MAXN][1<<MAXN];
int solve(vector<vector<int>> &adj, int n) {
 
	memset(memo, -1, sizeof memo);
 
	auto rec = [&](auto&& self, int u, int mask) -> int {
		if (mask == (1<<n) - 1) return u == n -1;
		if (u == n-1) return 0;
 
		auto& ret = memo[u][mask];
 
		if (ret != -1)
			return ret;
 
		ret = 0;
		for (auto v : adj[u]) {
			if (!(mask & (1<<v))) {
				ret = (ret + self(self, v, mask | (1<<v))) % mod;
			}
		}
 
		return ret;
	};
 
	return rec(rec, 0, 1);
}
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n, m;
	cin >> n >> m;
 
	vector<vector<int>> adj(n);
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
	}
 
	cout << solve(adj, n) << '\n';
 
}

// AC, grpahs , dynamic programming, hamiltonian paths
