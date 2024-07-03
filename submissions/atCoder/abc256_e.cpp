#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;	
	cin >> n;

	vector<int> xs(n);
	for (auto& xi : xs)
		cin >> xi, xi--;

	vector<ll> cs(n);
	for (auto& ci : cs)
		cin >> ci;

	vector<ll> hs(n);
	for (int i = 0; i < n; i++) {
		hs[xs[i]] += cs[i];
	}

	multiset<pair<ll, int>> st;
	for (int i = 0; i < n; i++) {
		st.emplace(hs[i], i);
	}

	ll ans = 0;
	vector<char> out(n);
	while (!st.empty()) {
		auto [v, idx] = *st.begin();

		st.erase(st.begin());

		out[idx] = 1;

		ans += v;

		
		if (!out[xs[idx]]) {
			st.erase(st.find({hs[xs[idx]], xs[idx]}));

			hs[xs[idx]] -= cs[idx];

			st.emplace(hs[xs[idx]], xs[idx]);
		}

	}

	cout << ans << '\n';
}

// AC, greddy, data structures
