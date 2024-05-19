#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
template <typename T>
vector<vector<T>> prod(vector<vector<T>> &a, vector<vector<T>> &b) {
	const T _oo = numeric_limits<T>::max();
	int n = a.size();
	vector<vector<T>> c(n, vector<T>(n, _oo));
 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (a[i][k] != _oo and b[k][j] != _oo)
					c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
 
	return c;
}
 
template <typename T>
vector<vector<T>> shortest_with_k_moves(vector<vector<T>> adj, ll k) {
	if (k == 1) return adj;

	auto ans = adj;
	k--;
 
 
	while (k) {
		if (k & 1) ans = prod(ans, adj);
		k >>= 1;
		adj = prod(adj, adj);
	}

	return ans;
}
 
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n ,m, k;
	cin >> n >> m >> k;
 
	vector<vector<ll>> ways(n, vector<ll>(n, numeric_limits<ll>::max()));
 
	for (ll i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		a--, b--;
 
		ways[a][b] = min(ways[a][b], c);
	}
	ways = shortest_with_k_moves(ways, k);
 
 
	cout << (ways[0][n-1] <= 1e18 ? ways[0][n-1] : -1) << '\n';
}

// AC, graphs, shortest paths, matrix exponentiation
