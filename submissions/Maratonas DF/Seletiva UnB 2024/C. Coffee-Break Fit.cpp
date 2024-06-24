#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n, m;
	cin >> n >> m;

	vector<ll> as(n);
	for (auto &ai : as) cin >> ai;

	for (int i = 0; i < n; i++) {
		ll bi;
		cin >> bi;

		as[i]-= bi;
		as[i] = max(as[i], 0ll);
	}

	vector<ll> cs(n);
	for (auto &ci : cs) cin >> ci;

	vector<ll> cs2;
	for (int i = 0; i < n; i++) {
		if (as[i]) {
			cs2.push_back(as[i] * cs[i]);
		}
	}

	sort(cs2.begin(), cs2.end());


	ll curcost = 0;
	ll cursum = 0;

	int ans = 0;
	for (int i = 0; i < cs2.size(); i++) {
		curcost += cs2[i] + cursum;
		cursum += cs2[i];

		if (curcost <= m) ans = i + 1;
		else break;
	}


	cout << ans << '\n';
}


// AC, greddy
