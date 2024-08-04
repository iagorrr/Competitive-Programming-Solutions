#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	ll x, y;
	cin >> x >> y;
	ll ans = 0;

	while (x < y) {
		x += 10;
		ans++;
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

// AC, math, brute force

