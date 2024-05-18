#include <bits/stdc++.h>
using namespace std;

using ll = long long;
auto run() {
	int n;
	cin >> n;


	map<ll, vector<ll>> per_power;
	map<pair<ll,ll>, int> id;
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		per_power[-a].push_back(b);
		id[{a,b}] = i;
	}

	ll min_cost = 2*1e9;
	vector<ll> ans;
	for (auto &[a, b] : per_power) {
		ll new_min = 2*1e9;
		for (auto bi : b) {
			if (bi <= min_cost) {
				ans.push_back(id[{-a,bi}]);
			}
			new_min = min(new_min, bi);
		}
		min_cost = min(min_cost, new_min);
	}

	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for (auto a : ans) {
		cout << a+1 << ' ';
	}
	cout << '\n';




}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, sortings
