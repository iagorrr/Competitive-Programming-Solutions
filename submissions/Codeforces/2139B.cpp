#include<bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
	ios_base::sync_with_stdio(!cin.tie(0));
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;

		vector<ll> as(n);
		for (auto& ai: as) cin >> ai;

		ll ans = 0;
		sort(rbegin(as), rend(as));

		for (int i = 0; i < min(m, n); i++) {
			ans += as[i] * (m-i);
		}

		cout << ans << '\n';

	}
}
