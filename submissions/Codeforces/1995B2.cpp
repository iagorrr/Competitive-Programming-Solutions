#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	int N;
	ll M;
	cin >> N >> M;

	vector<pair<ll,ll>> XS(N);
	for (auto& [a, b] : XS)
		cin >> a;

	for (auto& [a, b] : XS)
		cin >> b;

	sort(XS.begin(), XS.end());

	ll ans = 0;
	for (int i = 0; i < N; i++) {
		auto [x1, q1] = XS[i];
		ll k1 = min(M/x1, q1);

		ans = max(ans, x1 * k1);

		if (i + 1 == N)
			continue;

		auto [x2, q2] = XS[i+1];
		if (x2-x1 > 1) continue;

		ll k2 = min((M-(x1*k1))/x2, q2);
		ans = max(ans, x1*k1+x2*k2);

		ll r = min({k1,q2-k2,M-x1*k1-x2*k2});

		k1 -= r;
		k2 += r;
		ans = max(ans, x1*k1 + x2*k2);
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		run();
	}
}

// AC, math
