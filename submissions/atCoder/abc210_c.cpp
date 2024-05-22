#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;
	int k;
	cin >> k;

	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	map<int,int> hs;
	for (int i = 0; i < k; i++) {
		hs[xs[i]]++;
	}

	int ans = 0;
	ans = hs.size();
	for (int l = 0, r = k; r < n; l++, r++) {
		auto xl = xs[l];
		auto xr = xs[r];

		hs[xl]--;
		hs[xr]++;

		if (hs[xl] == 0) hs.erase(xl);
		ans = max(ans, (int)hs.size());
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, data-structures

