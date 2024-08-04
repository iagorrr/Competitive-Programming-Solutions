#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	ll N, X;

	cin >> N >> X;

	vector<ll> XS(N);
	for (auto &xi : XS)
		cin >> xi;
	ll ans = 0;

	map<ll,ll> hist;
	ll s = 0;
	hist[0] = 1;

	s = 0;
	for (int i = 0; i < N; i++) {
		s += XS[i];
		ll k = -(X-s);
		ans += hist[k];
		hist[s]++;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, math
