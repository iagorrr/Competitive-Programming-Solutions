#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, w;
	cin >> n >> w;

	vector<pair<ll,ll>> xs(n);
	for (auto &[a, b] : xs) {
		cin >> a >> b;
	}

	sort(xs.rbegin(), xs.rend());

	ll ans = 0;
	for (int i = 0; i < n and w; i++) {
		auto [a, b] = xs[i];
		ans = ans + min(w, b) * a;
		w = max(0ll, w - b);
	}

	cout << ans << '\n';
}


// AC, greddy
