#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (auto &x : as) cin >> x;

	int b = sqrt(n) + 1;

	ll ans = 0;

	for (int i = 0; i < n; i++) {

		ll ai = as.at(i);

		if (ai < b) {
			// como que evita duplicata aqui
			for (int k = 1; k < b and i + k * ai < n; k++) {
				if (as.at(i + k * ai) * ai == i + k * ai - i)
					ans++;
			}
		}
		else {

			int l = i -  ai, r = i + ai;
			while (l >= 0 or r < n) {
				if (l >= 0 and as.at(l) * ai == i - l) ans++;
				if (r < n and as.at(r) * ai == r - i) ans++;
				r += ai;
				l -= ai;
			}
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;

	while (t--) solve();
}
