#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	ll k;
	cin >> n >> k;

	vector<ll> xs(n);
	for (auto &xi : xs) cin >> xi;


	auto ys =  xs;
	sort(ys.begin(), ys.end());
	map<ll,ll> pos;
	for (ll i = 0; i < n; i++) {
		pos[ys[i]] = i;
	}

	for (auto xi : xs) {
		ll ans = k / n + (pos[xi] < (k%n));
		cout << ans << '\n';
	}


}

// AC, greddy, math
