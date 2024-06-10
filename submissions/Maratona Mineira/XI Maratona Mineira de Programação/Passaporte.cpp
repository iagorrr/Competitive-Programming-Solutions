#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1'00'000;
const int MAXK = 1'00;
const int OO = 1'000'000'000;

int memo[MAXN+1][MAXK+1];

vector<pair<int, int>> adj[MAXN];
int solve(int u, int du) {
	if (du < 0) return OO;

	if (u == 0 and du == 0) return 0;

	auto &ans = memo[u][du];
	if (ans != -1) return ans;

	ans = OO;

	for (auto &[v, w] : adj[u]) {
		ans = min(ans, solve(v, du - w) + 1);
	}

	return ans;
}


int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(memo, -1, sizeof memo);

	ll n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		ll w;
		cin >> w;
		adj[v].emplace_back(u, w);
	}

	int ans = OO;
	for (int i = 0; i <= k; i++) {
		ans = min(ans, solve(n-1, i));
	}

	cout << (ans == OO ? -1 : ans) << '\n';
}

// AC, dynamic programming
