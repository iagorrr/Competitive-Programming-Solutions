#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	map<ll, vector<ll>> mp;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		mp[a].push_back(b);
	}

	ll ans = 0;
	for (auto &[_, xs] : mp) {
		sort(xs.begin(), xs.end());
		ll avg = xs[xs.size()/2ll];
		if (!(xs.size() & 1)) {
			avg += xs[xs.size()/2ll-1];
			avg/=2ll;
		}

		for (auto xi : xs) {
			ans += abs(xi - avg);
		}
	}

	cout << ans << '\n';


}

// AC, sortings
