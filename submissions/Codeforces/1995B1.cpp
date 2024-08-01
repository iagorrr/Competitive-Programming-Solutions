#include <bits/stdc++.h>
using namespace std;

using ll = long long;

auto run() {
	int N;
	cin >> N;

	ll M;
	cin >> M;

	map<ll, ll> cnt;
	for (int i = 0; i < N; i++) {
		ll xi;
		cin >> xi;
		cnt[xi]++;
	}

	vector<pair<ll,ll>> xs;
	for (auto [a, b] : cnt)
		xs.emplace_back(a, b);

	sort(xs.begin(), xs.end());

	ll ans = 0;
	for (int i = 0; i < xs.size(); i++) {
		auto [x1, q1] = xs[i];

		for (ll k = 0;  k <= q1; k++) {
			ll cost = k *  x1;
			if (cost > M)
				continue;
			ans = max(ans, cost);

			ll left = M - cost;
			if (!left) continue;

			if (i + 1 < xs.size()) {
				auto [x2, q2] = xs[i+1];
				if (abs(x2-x1) <= 1) {
					ll cost2 = min(left/x2,q2)*x2;
					ans = max(ans, cost + cost2);
				}

			}

			if (i) {
				auto [x2, q2] = xs[i-1];
				if (abs(x2-x1) <= 1) {
					ll cost2 = min(left/x2,q2)*x2;
					ans = max(ans, cost + cost2);
				}

			}

		}
	}

	assert(ans <= M);

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T = 1;
	cin >> T;

	for (int i = 1; i <= T; i++) {
		run();
	}

}

// AC, math, brute force
