#include <bits/stdc++.h>
using namespace std;

auto run() {
	int n;
	cin >> n;
	vector<int> xs(n);
	for (auto &xi : xs) cin >> xi;

	if (n == 2) {
		cout << 0 << '\n';
		return;
	}

	auto xs2 = xs;
	sort(xs.begin(), xs.end());


	sort(xs2.begin(), xs2.end());
	reverse(xs2.begin(), xs2.end());

	int ans = 0;
	ans = min( {
			xs.back() - xs.front(),
			xs[n-2] - xs.front(),
			xs.back() - xs[1]
			});

	cout << ans << '\n';

}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	run();
}

// AC, sortings, greddy
