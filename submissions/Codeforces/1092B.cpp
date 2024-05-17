#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;
	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;
	sort(xs.begin(), xs.end());

	int ans = 0;

	for (int i = 0;i  < n; i+=2) {
		ans += abs(xs[i]- xs[i+1]);
	}

	cout << ans << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt = 1;
//	cin >> tt;

	while (tt--) {
		run();
	}
}


// AC, greddy, sortings
