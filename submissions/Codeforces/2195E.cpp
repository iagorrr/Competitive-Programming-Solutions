#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 1'000'000'000 + 7;

ll add(ll a, ll b) {
	return (a+b)%mod;
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

ll sub(ll a, ll b) {
	return (a - b + mod) % mod;
	a -= b;
	if (a < mod) a += mod;
	return a;
}

ll mul(ll a, ll b) {
	return (a * b) % mod;
}


void solve() {
	int n;
	cin >> n;

	vector<int> rs(n+1);
	vector<int> ls(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> ls[i] >> rs[i];
	}

	vector<ll> mem(n+1, -1);
	auto fv = [&](auto&& self, int u) {
		if (u == 0) return 1ll;

		auto& ret = mem[u];
		if (~ret) return ret;

		ret = 1;
		if (ls[u]) ret = add(add(ret, self(self, ls[u])),  1);
		if (rs[u]) ret = add(add(self(self, rs[u]), ret), 1);

		return ret;
	};

	vector<ll> ans(n+1, 0);
	ll acc = 0;
	auto dfs = [&](auto&& self, int u, int p) -> void {

		acc = add(acc ,  fv(fv, u)); 

		ans[u] = acc;

		if (ls[u]) self(self, ls[u], u);
		if (rs[u]) self(self, rs[u], u);

		acc = sub(acc , fv(fv, u));
	};

	dfs(dfs, 1, 0);


	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;

	while (t--) solve();
}
